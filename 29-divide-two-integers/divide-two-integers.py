class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        negative = (dividend < 0) ^ (divisor < 0)

        a, b = abs(dividend), abs(divisor)
        res = 0

        for i in range(31, -1, -1):
            if (a >> i) >= b:
                res += 1 << i
                a  -= b << i

        if negative:
            res = -res

        if res > INT_MAX: return INT_MAX
        if res < INT_MIN: return INT_MIN
        return res
