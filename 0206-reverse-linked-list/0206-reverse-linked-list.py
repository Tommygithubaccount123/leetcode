# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        
        pointer = head
        cur = head
        prev = None
        while (pointer):
            pointer = pointer.next
            cur.next = prev
            prev = cur
            cur = pointer
        return prev