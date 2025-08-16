#include <stdlib.h>
#include <stdint.h>

/* Simple open-addressing hash table: key = nums[i], value = index i */
typedef struct {
    int   cap;     // capacity (power of two)
    int  *keys;    // keys (nums[i])
    int  *vals;    // values (indices)
    unsigned char *used;  // 0 = empty, 1 = occupied
} Hash;

/* Knuth multiplicative hash for 32-bit integers (handles negatives via cast) */
static inline uint32_t hash_int(int x) {
    return (uint32_t)x * 2654435761u;
}

static int next_pow2(int x) {
    int p = 1;
    while (p < x) p <<= 1;
    return p;
}

static int hash_init(Hash *h, int min_cap) {
    if (min_cap < 8) min_cap = 8;
    h->cap  = next_pow2(min_cap);
    h->keys = (int*)malloc(h->cap * sizeof(int));
    h->vals = (int*)malloc(h->cap * sizeof(int));
    h->used = (unsigned char*)calloc(h->cap, sizeof(unsigned char));
    if (!h->keys || !h->vals || !h->used) {
        free(h->keys); free(h->vals); free(h->used);
        return 0;
    }
    return 1;
}

static void hash_free(Hash *h) {
    free(h->keys); free(h->vals); free(h->used);
}

/* Look up key; if found, write value to *out and return 1, else return 0 */
static int hash_get(const Hash *h, int key, int *out) {
    uint32_t idx = hash_int(key) & (h->cap - 1);
    while (h->used[idx]) {
        if (h->keys[idx] == key) { *out = h->vals[idx]; return 1; }
        idx = (idx + 1) & (h->cap - 1);
    }
    return 0;
}

/* Insert or overwrite key -> val */
static void hash_put(Hash *h, int key, int val) {
    uint32_t idx = hash_int(key) & (h->cap - 1);
    while (h->used[idx]) {
        if (h->keys[idx] == key) { h->vals[idx] = val; return; }
        idx = (idx + 1) & (h->cap - 1);
    }
    h->used[idx] = 1;
    h->keys[idx] = key;
    h->vals[idx] = val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    if (numsSize < 2) return NULL;

    Hash h;
    /* Use ~2*n buckets (rounded up to a power of two) to keep load factor low */
    if (!hash_init(&h, numsSize * 2)) return NULL;

    for (int i = 0; i < numsSize; ++i) {
        int need = target - nums[i];
        int j;
        /* Check complement BEFORE inserting current element to avoid reusing it */
        if (hash_get(&h, need, &j)) {
            int *ans = (int*)malloc(2 * sizeof(int));
            if (!ans) { hash_free(&h); return NULL; }
            ans[0] = j;
            ans[1] = i;
            *returnSize = 2;
            hash_free(&h);
            return ans;
        }
        hash_put(&h, nums[i], i);
    }

    /* Problem guarantees one solution, but return NULL defensively */
    hash_free(&h);
    return NULL;
}
