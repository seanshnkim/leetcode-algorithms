#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int l = 0, r = N-1;
        int left_h = height[l], right_h = height[r];
        int max_amt = min(left_h, right_h)*(r-l);

        while (r > l+1) {
            if (right_h < left_h) {
                r--;
                if (height[r] <= right_h) {
                    // right_h = height[r];
                    continue;
                }
            }
            else {
                l++;
                if (height[l] <= left_h) {
                    // left_h = height[l];
                    continue;
                }
            }
            int cur_amt = min(height[l], height[r]) * (r-l);
            max_amt = max(cur_amt, max_amt);
            left_h = height[l], right_h = height[r];
        }
        return max_amt;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;
    return 0;
}