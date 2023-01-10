import typing

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        

def insertionSortList(self, head: ListNode) -> ListNode:
    cur = parent = ListNode(None)
    while head:
        while cur.next and cur.next.val < head.val:
            cur = cur.next
        
        cur.next, head.next, head = head, cur.next, head.next
        
        cur = parent
    return cur.next

