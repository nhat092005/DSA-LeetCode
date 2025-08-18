#include <limits.h> // INT_MIN / INT MAX

static inline int max2(int a, int b) { return a > b ? a : b; }
static inline int min2(int a, int b) { return a < b ? a : b; }

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Make sure nums1 shorter than num2s
    int *A = nums1, *B = nums2;
    int m = nums1Size, n = nums2Size;
    if (m > n)
    {
        A = nums2;
        B = nums1;
        m = nums2Size;
        n = nums1Size;
    }

    int total = m + n;
    int half = (total + 1) / 2;

    int l = 0, r = m;
    while (l <= r)
    {
        int i = (l + r) / 2;    // cut in A
        int j = half - i;       // Cut in B

        int Aleft   = (i > 0) ? A[i - 1] : INT_MIN;
        int Aright  = (i < m) ? A[i] : INT_MAX;
        int Bleft   = (j > 0) ? B[j - 1] : INT_MIN;
        int Bright  = (j < n) ? B[j] : INT_MAX;

        if (Aleft <= Bright && Bleft <= Aright)
        {
            if (total & 1) return (double)max2(Aleft, Bleft);   // odd length
            else
            {
                int leftMax  = max2(Aleft, Bleft);
                int rightMax = min2(Aright, Bright);
                return (leftMax + rightMax) / 2.0;              // even length
            }
        }
        else if (Aleft > Bright) r = i - 1;
        else l = i + 1;
    }
    return 0.0;
}