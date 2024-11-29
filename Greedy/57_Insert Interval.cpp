#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size();
        int mergedStart = newInterval[0];
        int mergedEnd = newInterval[1];
        vector<vector<int>> newIntervals;
        
        if (N == 0) {
            newIntervals.push_back(newInterval);
            return newIntervals;
        }
        int i = 0;
        while (i < N) {
            if (is_overlapped(intervals[i], newInterval) ) {
                mergedStart = min(intervals[i][0], newInterval[0]);
                i++;
                while (i < N && is_overlapped(intervals[i], newInterval) ) {
                    i++;
                }
                mergedEnd = max(intervals[i-1][1], newInterval[1]);
                vector<int> mergedInterval = {mergedStart, mergedEnd};
                newIntervals.push_back(mergedInterval);
            }
            else {
                // This order of if statements matter, because newIntervals need to be sorted by `start`
                if (i == 0 && newInterval[1] < intervals[i][0]) {
                    newIntervals.push_back(newInterval);
                }
                newIntervals.push_back(intervals[i]);

                if ( (i < N-1  && newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i+1][0]) ||
                     (i == N-1 && newInterval[0] > intervals[i][1]) ) {
                    newIntervals.push_back(newInterval);
                }
                i++;
            }
        }
        return newIntervals;
    }
private:
    bool is_overlapped(vector<int>& interval, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        return !(newEnd < interval[0] || newStart > interval[1]);
    }
};

void print_vectorOfVectors(vector<vector<int>> vecs) {
    cout << '[';
    for (int i=0; i < vecs.size(); i++) {
        cout << '[';
        for (auto j: vecs[i]) {
            cout << j << ', ';
        }
        cout << '], ';
    }
    cout << ']' << endl;    
}

int main()
{
    Solution sol;

    vector<vector<int>> intervals1 = {{1,3},{6,9}};
    vector<int> newInterval1 = {2,5};

    vector<vector<int>> intervals2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval2 = {4,8};

    vector<vector<int>> intervals3 = {{1,5}};
    vector<int> newInterval3 = {6,8};
    
    vector<vector<int>> intervals4 = {{1,5}};
    vector<int> newInterval4 = {0,3};
    
    vector<vector<int>> newIntervals1 = sol.insert(intervals1, newInterval1);
    vector<vector<int>> newIntervals2 = sol.insert(intervals2, newInterval2);
    vector<vector<int>> newIntervals3 = sol.insert(intervals3, newInterval3);
    vector<vector<int>> newIntervals4 = sol.insert(intervals4, newInterval4);
    
    print_vectorOfVectors(newIntervals1);
    print_vectorOfVectors(newIntervals2);
    print_vectorOfVectors(newIntervals3);
    print_vectorOfVectors(newIntervals4);

    return 0;
}