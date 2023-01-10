def quicksort(A, lo, hi):
    def partition(lo, hi):
        global cnt
        cnt += 1
        pivot = A[hi]
        left = lo
        for right in range(lo, hi):
            if A[right] < pivot:
                A[left], A[right] = A[right], A[left]
                left += 1
        A[left], A[hi] = A[hi], A[left]
        return left
    
    if lo < hi:
        pivot = partition(lo, hi)
        quicksort(A, lo, pivot - 1)
        quicksort(A, pivot + 1, hi)

if __name__ == "__main__":
    test_list = [5,4,3,2,1]
    cnt = 0
    
    quicksort(test_list, 0, len(test_list) - 1)
    
    # 4
    print(cnt)
    