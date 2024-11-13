from typing import List

# bad code
'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals, key=lambda x: x[0])
        num_intervals = len(sorted_intervals)
        for i in range(num_intervals - 1):
            criteria = sorted_intervals[i]
            for j in range(i+1, num_intervals):
                if criteria[1] >= sorted_intervals[j][0]:
                    sorted_intervals[i][1] = sorted_intervals[j][1]
                    sorted_intervals.pop(j)
                else:
                    break
        return sorted_intervals
'''

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        for interv in sorted(intervals, key=lambda x: x[0]):
            if merged and interv[0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], interv[1])
            else:
                merged.append(interv)
        return merged
    
    
if __name__ == "__main__":
    test = Solution()
    input = [[1,3], [2,6], [8,10], [15,18]]
    test.merge(input)