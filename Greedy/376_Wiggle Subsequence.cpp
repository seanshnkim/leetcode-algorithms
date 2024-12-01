#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        vector<int> up(nums.size());
        vector<int> down(nums.size());
        up[0] = down[0] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        
        return max(down[nums.size() - 1], up[nums.size() - 1]);
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,7,4,9,2,5};
    vector<int> nums2 = {3,3,3,2,5};
    vector<int> nums3 = {1,17,5,10,13,15,10,5,16,8};

    cout << sol.wiggleMaxLength(nums1) << endl;
    cout << sol.wiggleMaxLength(nums2) << endl;
    cout << sol.wiggleMaxLength(nums3) << endl;

    return 0;
}