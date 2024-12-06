#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int N = points.size();
        sort(points.begin(), points.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(points[0][1]);
        int cnt = 1;

        for (int i=1; i < N; i++) {
            int first_pop = pq.top();
            if (points[i][0] > first_pop) {
                while(!pq.empty()) {pq.pop();};
                cnt++;
                pq.push(points[i][1]);
            }
            else {
                if (points[i][1] < pq.top()) {
                    pq.push(points[i][1]);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points1 = {{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> points2 = {{1,2},{3,4},{5,6},{7,8}};
    vector<vector<int>> points3 = {{1,2},{2,3},{3,4},{4,5}};
    cout << sol.findMinArrowShots(points1) << endl;
    cout << sol.findMinArrowShots(points2) << endl;
    cout << sol.findMinArrowShots(points3) << endl;
    return 0;
}