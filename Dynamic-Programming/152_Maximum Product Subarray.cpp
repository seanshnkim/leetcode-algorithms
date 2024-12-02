#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 0);
        dp[0] = nums[0];
        for (int i=1; i < N; i++){
            dp[i] = max(nums[i]*dp[i-1], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2,3,-2,4};
    cout << sol.maxProduct(nums1) << endl;
    return 0;
}