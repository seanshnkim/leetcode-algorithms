from typing import List

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


# def insertion_sort(input: List):
#     sorted = []
#     if input:
#         sorted.append(input.pop(0))
#     for i in input:
#         for j in reversed(range(len(sorted))):
#             while i < sorted[j]:
#                 j -= 1
#             sorted.insert(j+1, i)
#     return sorted


def insertion_sort(input: List):
    sorted = []
    
    for num in input:
        if sorted:
            len_sorted = len(sorted)
            for s in range(len_sorted):
                if num < sorted[s]:
                    sorted.insert(s, num)
                    break
        else:
            sorted.append(num)
    
    return sorted


if __name__ == '__main__':
    # head = ListNode(4)
    # head.next = ListNode(2)
    # head.next.next = ListNode(1)
    # head.next.next.next = ListNode(3)
    
    input_list = [4,3,2,1]
    insertion_sort(input_list)
    
    