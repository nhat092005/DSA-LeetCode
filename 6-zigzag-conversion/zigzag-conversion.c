#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    int n = (int)strlen(s);
    char *out = (char*)malloc((size_t)n + 1);
    if (!out) return NULL;

    // Trivial case
    if (numRows == 1 || numRows >=n)
    {
        memcpy(out, s, (size_t)n + 1);
        return out;
    }

    // Create buffer for each row
    char **rows = (char**)malloc((size_t)numRows * sizeof(char*));
    int *len    = (int*)calloc((size_t)numRows, sizeof(int));
    if (!rows || !len)
    {
        free(out);
        free(rows);
        free(len);
        return NULL;
    }

    for (int r = 0; r < numRows; ++r)
    {
        rows[r] = (char*)malloc((size_t)n + 1);
        if (!rows[r])
        {
            for (int k = 0; k <= r; ++r) free(rows[k]);
            free(out);
            free(rows);
            free(len);
            return NULL;
        }
        rows[r][0] = '\0';
    }

    // Simulate zigzag
    int row = 0, step = 1;
    for (int i = 0; i < n; ++i)
    {
        rows[row][len[row]++] = s[i];

        if (row == 0) step = 1;                     // bounce at top
        else if (row == numRows - 1) step = -1;     // bounce at bottom
        row += step;
    }

    // Result
    int k = 0;
    for (int r = 0; r < numRows; ++r)
    {
        memcpy(out + k, rows[r], (size_t)len[r]);
        k += len[r];
        free(rows[r]);
    }
    out[k] = '\0';
    
    free(rows);
    free(len);
    return out;
}
