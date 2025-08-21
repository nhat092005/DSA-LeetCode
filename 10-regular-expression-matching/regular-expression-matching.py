class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        n, m = len(s), len(p)
        memo = {}

        def dp(i, j):
            """Return True if s[i:] matches p[j:]."""
            if (i, j) in memo:
                return memo[(i, j)]

            if j == m:
                memo[(i, j)] = (i == n)
                return memo[(i, j)]

            first = (i < n) and (p[j] == s[i] or p[j] == '.')

            if j + 1 < m and p[j + 1] == '*':
                ans = dp(i, j + 2) or (first and dp(i + 1, j))
            else:
                ans = first and dp(i + 1, j + 1)

            memo[(i, j)] = ans
            return ans

        return dp(0, 0)
