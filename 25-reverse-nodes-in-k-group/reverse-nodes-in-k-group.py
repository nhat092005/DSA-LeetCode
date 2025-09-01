# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        if k <= 1 or not head:
            return head

        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            kth = groupPrev
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next

            groupNext = kth.next

            prev, cur = groupNext, groupPrev.next
            while cur != groupNext:
                nxt = cur.next
                cur.next = prev
                prev = cur
                cur = nxt

            oldGroupHead = groupPrev.next 
            groupPrev.next = kth
            groupPrev = oldGroupHead