#include <stdlib.h>
#include <string.h>

int expand_len(const char *s, int n, int L, int R)
{
    while (L >= 0 && R <= n && s[L] == s[R])
    {
        --L; ++R;
    }
    return R - L - 1;
}

char* longestPalindrome(char* s) {
   if (!s) return NULL;
   int n = (int)strlen(s);
   if (n <= 1)
   {
    char *res = (char*)malloc((size_t)n + 1);
    if (res) memcpy(res, s, (size_t)n + 1);
    else return NULL;
    return res;
   }

   int bestLen = 1;
   int start = 0;

   for (int i = 0; i < n; i++)
   {
    int len1 = expand_len(s, n, i, i);      // odd-length center
    int len2 = expand_len(s, n, i, i +1);   // even-length center
    int len = (len1 > len2) ? len1 : len2;

    if (len > bestLen)
    {
        start = i - (len - 1) / 2;
        bestLen = len;
    }
   }

   char *ans = (char*)malloc((size_t)bestLen + 1);
   if (!ans) return NULL;
   memcpy(ans, s + start, (size_t)bestLen);
   ans[bestLen] = '\0';
   return ans;
}