# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        first = 0
        counter = 0
        while (l1):
            first += l1.val * 10**counter
            l1 = l1.next
            counter += 1
        second = 0
        counter = 0
        while (l2):
            second += l2.val * 10**counter
            l2 = l2.next
            counter += 1

        total = first + second
        print(first, second)
        if total == 0:
            return ListNode(0)
        prev = None
        head = None

        while (total):
            node_val = total % 10
            total /= 10
            node = ListNode(node_val)
            if prev:
                prev.next = node
            else:
                head = node
            prev = node
        return head