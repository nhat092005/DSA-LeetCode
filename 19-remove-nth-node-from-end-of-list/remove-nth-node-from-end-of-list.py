# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        l = head
        r = head
        for _ in range(n):
            r = r.next

        if not r:
            return head.next

        while r.next:
            r = r.next
            l = l.next

        l.next = l.next.next

        return head