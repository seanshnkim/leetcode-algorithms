#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int start_idx = -1;
        for (int i = 0; i < N; i++) {
            start_idx = rotate(i, gas, cost);
            if (start_idx != -1) {
                return start_idx;
            }
        }
        return start_idx;
    }
private:
    int rotate(int idx, vector<int>& gas, vector<int>& cost) {
        int rem_gas = gas[idx];
        int N = gas.size();
        
        for (int j=0; j < N; j++) {
            if (rem_gas >= cost[(idx+j)%N]) {
                rem_gas += gas[(idx+j+1)%N] - cost[(idx+j)%N];
            }
            else {
                return -1;
            }
        }
        return idx;
    }
};

int main()
{
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}