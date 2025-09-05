class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []

        Ls = set(map(len, words))
        if len(Ls) != 1:
            return []
            
        L = Ls.pop()
        total = L * len(words)
        if len(s) < total:
            return []

        need = Counter(words)
        res = []
        n = len(s)

        for offset in range(L):
            left = right = offset
            seen = Counter()
            count = 0

            while right + L <= n:
                w = s[right:right+L]
                right += L

                if w in need:
                    seen[w] += 1
                    count += 1
                    
                    while seen[w] > need[w]:
                        wl = s[left:left+L]
                        seen[wl] -= 1
                        left += L
                        count -= 1

                    if count == len(words):
                        res.append(left)
                        wl = s[left:left+L]
                        seen[wl] -= 1
                        left += L
                        count -= 1
                else:
                    seen.clear()
                    count = 0
                    left = right
        return res      