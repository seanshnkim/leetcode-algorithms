from typing import List

# First trial:
'''
nums = [0,0]
Output: "00"
Expected: "0"

def largestNumber(nums: List[int]) -> str:
    sorted = []
    
    nums_str = [str(n) for n in nums]
    
    for n_str in nums_str:
        if sorted:
            for i in range(len(sorted)):
                s = sorted[i]
                if int(n_str + s) > int(s + n_str):
                    sorted.insert(i, n_str)
                    break
                elif i == len(sorted) - 1:
                    sorted.append(n_str)
        else:
            sorted.append(n_str)
    
    return "".join(sorted)
'''


def largestNumber(nums: List[int]) -> str:
    sorted = []
    
    nums_str = [str(n) for n in nums]
    
    for n_str in nums_str:
        if sorted:
            for i in range(len(sorted)):
                s = sorted[i]
                if int(n_str + s) > int(s + n_str):
                    sorted.insert(i, n_str)
                    break
                elif i == len(sorted) - 1:
                    sorted.append(n_str)
        else:
            sorted.append(n_str)
    
    
    return "".join(sorted)



if __name__ == '__main__':
    nums = [3,30,34,5,9]
    
    print(largestNumber(nums))