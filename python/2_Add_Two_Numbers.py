# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def printList(self, x):
        while (x != None):
            print(x.val)
            x = x.next

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = tail = None
        flag = 0
        while l1 != None or l2 != None:
            if l1 != None and l2 != None:
                node = ListNode((l1.val + l2.val + flag) % 10)
                flag = int((l1.val + l2.val + flag)/10)
                l1 = l1.next
                l2 = l2.next
            elif l1 == None and l2 != None:
                node = ListNode((l2.val + flag) % 10)
                flag = int((l2.val + flag)/10)
                l2 = l2.next
            elif l1 != None and l2 == None:
                node = ListNode((l1.val + flag) % 10)
                flag = int((l1.val + flag)/10)
                l1 = l1.next

            if head == None:
                head = tail = node
            else:
                tail.next =  node
                tail = node

        if flag == 1:
            node = ListNode(1)
            tail.next =  node
            tail = node

        return head

lnode1 = ListNode(2)
lnode2 = ListNode(4)
lnode3 = ListNode(3)
lnode1.next = lnode2
lnode2.next = lnode3

rnode1 = ListNode(5)
rnode2 = ListNode(6)
rnode3 = ListNode(4)
rnode1.next = rnode2
rnode2.next = rnode3

sol = Solution()
head = sol.addTwoNumbers(lnode1, rnode1)
head.printList(head)

        