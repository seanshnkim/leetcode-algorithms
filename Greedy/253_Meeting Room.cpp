#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort by the first element
        sort(intervals.begin(), intervals.end());
        int N = intervals.size();

        int cnt = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);

        for (int i=1; i < N; i++) {
            if (intervals[i][0] < pq.top()) {
                cnt++;
            }
            else {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{0,30}, {5,10}, {15,20} };
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4} };
    vector<vector<int>> intervals3 = {{1,8},{6,20},{9,16},{13,17}};
    vector<vector<int>> intervals4 = {{2,15},{36,45},{9,29},{16,23},{4,9}};
    cout << sol.minMeetingRooms(intervals) << endl;
    cout << sol.minMeetingRooms(intervals2) << endl;
    cout << sol.minMeetingRooms(intervals3) << endl;
    return 0;
}