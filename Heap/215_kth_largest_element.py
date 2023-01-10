import heapq
from collections import Counter

listA = [3,2,3,1,2,4,5,5,6]

freqs = Counter(listA)
print(Counter(listA))

for k in freqs:
    # print keys
    print(k)

#################!SECTION
import heapq
from typing import List

def findKthLargest1(nums: List[int], k: int) -> int:
    heap = list()
    for n in nums:
        heapq.heappush(heap, -n)

    for _ in range(1, k):
        heapq.heappop(heap)
        
    return (-1) * heapq.heappop(heap)


def findKthLargest2(nums: List[int], k: int) -> int:
    heapq.heapify(nums)
    
    for _ in range(len(nums) - k):
        heapq.heappop(nums)
    
    return heapq.heappop(nums)


def findKthLargest3(nums: List[int], k: int) -> int:
    heapq._heapify_max(nums)
    
    return heapq._heappop_max(nums)


def findKthLargest4(nums: List[int], k: int) -> int:
    return heapq.nlargest(k, nums)[-1]


def findKthLargest5(nums: List[int], k: int) -> int:
    return sorted(nums, reverse=True)[k-1]