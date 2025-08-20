#include <limits.h>  // INT_MIN, INT_MAX

// INT_MAX = 2147483647
// INT_MIN = -2147483648

int reverse(int x) {
    int res = 0;
    while (x != 0) {
        int pop = x % 10;   // last digit (works for negatives too)
        x /= 10;

        // Check overflow before res = res*10 + pop
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0;

        res = res * 10 + pop;
    }
    return res;
}
