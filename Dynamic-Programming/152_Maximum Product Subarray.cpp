#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        // first = positive, second = negative
        vector<pair<int, int>> dp(N);
        if (nums[0] > 0) {
            dp[0].first = nums[0];
            dp[0].second = 0;
        }
        else if (nums[0] < 0) {
            dp[0].first = 0;
            dp[0].second = nums[0];
        }
        else {
            dp[0].first = 0;
            dp[0].second = 0;
        }
        dp[0] = {nums[0], 0};
        for (int i=1; i < N; i++){
            if (nums[i] < 0) {
                if (dp[i-1].first == 0 && dp[i-1].second < 0) {
                    dp[i].first  = dp[i-1].second * nums[i];
                    dp[i].second = nums[i];
                }
                else if (dp[i-1].first > 0 && dp[i-1].second == 0) {
                    dp[i].first  = 0;
                    dp[i].second = dp[i-1].first * nums[i];
                }
                else if (dp[i-1].first > 0 && dp[i-1].second < 0) {
                    dp[i].first  = dp[i-1].second * nums[i];
                    dp[i].second = dp[i-1].first * nums[i];
                }
                else {
                    dp[i].first = 0;
                    dp[i].second = nums[i];
                }
            }
            else if (nums[i] > 0) {
                if (dp[i-1].first == 0 && dp[i-1].second < 0) {
                    dp[i].first  = nums[i];
                    dp[i].second = dp[i-1].second * nums[i];
                }
                else if (dp[i-1].first > 0 && dp[i-1].second == 0) {
                    dp[i].first  = dp[i-1].first * nums[i];
                    dp[i].second = 0;
                }
                else if (dp[i-1].first > 0 && dp[i-1].second < 0) {
                    dp[i].first  = dp[i-1].first * nums[i];
                    dp[i].second = dp[i-1].second * nums[i];
                }
                else {
                    dp[i].first = nums[i];
                    dp[i].second = 0;
                }
            }
        }
        int max_product = nums[0];
        for (int i=1; i < N; i++) {
            max_product = max(dp[i].first, max_product);
        }
        return max_product;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2,3,-2,4};
    cout << sol.maxProduct(nums1) << endl;
    return 0;
}