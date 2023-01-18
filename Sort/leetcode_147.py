import typing

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        

def insertionSortList(head: ListNode) -> ListNode:
    cur = parent = ListNode(None)
    while head:
        while cur.next and cur.next.val < head.val:
            cur = cur.next
        print(f"id cur: {id(cur)}\nid head: {id(head)}\n\
id cur.next: {id(cur.next)}\nid head.next: {id(head.next)}\n\
id head.next.next: {id(head.next.next)}")
        
        cur.next, head.next, head = head, cur.next, head.next
        
        print(f"id cur: {id(cur)}\nid head: {id(head)}\n\
id cur.next: {id(cur.next)}\nid head.next: {id(head.next)}\n\
id cur.next.next: {id(cur.next.next)}\n\
id head.next.next: {id(head.next.next)}\n")
        
        cur = parent
    return cur.next


if __name__ == '__main__':
    head = ListNode(4)
    head.next = ListNode(2)
    head.next.next = ListNode(1)
    head.next.next.next = ListNode(3)
    
    insertionSortList(head)