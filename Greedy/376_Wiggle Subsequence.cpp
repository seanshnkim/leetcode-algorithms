#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        vector<int> up(nums.size(), 0);
        vector<int> down(nums.size(), 0);
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                } else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        
        return 1 + max(down[nums.size() - 1], up[nums.size() - 1]);
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