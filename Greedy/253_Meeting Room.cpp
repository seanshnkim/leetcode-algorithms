#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort by the first element
        sort(intervals.begin(), intervals.end());
        int N = intervals.size();
        int cnt = 1;
        pair<int, int> range = {intervals[0][0], intervals[0][1]};
        int earliest_end = range.second;
        int max_cnt = cnt;
        for(int i=1; i < N; i++) {
            int int_start = intervals[i][0];
            int int_end = intervals[i][1];
            if (int_start < range.second) {
                if (int_start < earliest_end) {
                    cnt++;
                }
                else {
                    range.first = int_start;
                }
                earliest_end = min(range.second, int_end);
                range.second = max(range.second, int_end);
            }
            else {
                range.first = int_start;
                range.second = int_end;
                earliest_end = range.second;
                cnt = 1;
            }
            
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{0,30}, {5,10}, {15,20} };
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4} };
    vector<vector<int>> intervals3 = {{1,8},{6,20},{9,16},{13,17}};
    cout << sol.minMeetingRooms(intervals) << endl;
    cout << sol.minMeetingRooms(intervals2) << endl;
    cout << sol.minMeetingRooms(intervals3) << endl;
    return 0;
}