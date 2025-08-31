# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []
        tie = count()

        for node in lists:
            if node:
                heapq.heappush(pq, (node.val, next(tie), node))

        dummy = ListNode()
        cur = dummy

        while pq:
            _, _, node = heapq.heappop(pq)
            cur.next = node
            cur = cur.next
            if node.next:
                heapq.heappush(pq, (node.next.val, next(tie), node.next))

        return dummy.next