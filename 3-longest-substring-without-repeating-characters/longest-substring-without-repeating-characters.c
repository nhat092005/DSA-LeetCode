#include <stddef.h>

int lengthOfLongestSubstring(char *s) {
    // last[c] = last seen index of character c; -1 means "not seen yet"
    int last[256];
    for (int i = 0; i < 256; ++i) last[i] = -1;

    int best = 0;
    int L = 0;  // left edge of the sliding window

    for (int R = 0; s[R] != '\0'; ++R) {
        // Use unsigned char so we index 0..255 even if 'char' is signed
        unsigned char c = (unsigned char)s[R];

        // If 'c' was seen inside the current window, move L past its previous index
        if (last[c] >= L) {
            L = last[c] + 1;
        }

        // Window [L..R] is now duplicate-free; update the best length
        int len = R - L + 1;
        if (len > best) best = len;

        // Always record the latest index of this character
        last[c] = R;
    }
    return best;
}
