class Solution(object):
    def generateParenthesis(self, n):
        res = []

        def bt(cur, open_used, close_used):
            if len(cur) == 2 * n:
                res.append(cur)
                return
            if open_used < n:
                bt(cur + "(", open_used + 1, close_used)
            if close_used < open_used:
                bt(cur + ")", open_used, close_used + 1)

        bt("", 0, 0)
        return res
