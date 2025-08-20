#include <limits.h>   // INT_MIN, INT_MAX

int myAtoi(const char *s) {
    const char *p = s;

    // Skip leading spaces
    while (*p == ' ') p++;

    // Sign
    int sign = 1;
    if (*p == '+' || *p == '-') {
        if (*p == '-') sign = -1;
        p++;
    }

    // Read digits with overflow clamp
    int res = 0;
    bool read_any = false;

    while (*p >= '0' && *p <= '9') {
        int d = *p - '0';
        read_any = true;

        if (sign == 1) {
            // check before res = res*10 + d
            if (res > INT_MAX/10 || (res == INT_MAX/10 && d > 7)) return INT_MAX;
            res = res*10 + d;
        } else {
            // accumulate as negative to symmetrically clamp to INT_MIN
            if (res < INT_MIN/10 || (res == INT_MIN/10 && d > 8)) return INT_MIN;
            res = res*10 - d;
        }
        p++;
    }

    if (!read_any) return 0;
    return res;
}
