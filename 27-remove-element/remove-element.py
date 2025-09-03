class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        write = 0
        for x in nums:
            if x != val:
                nums[write] = x
                write += 1
        return write