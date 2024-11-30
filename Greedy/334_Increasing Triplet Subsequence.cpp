#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) {return false;}

        bool second_exists = false;
        int min = nums[0];
        int second = INT_MAX;

        for (int i=1; i < N; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
            else if (nums[i] > min) {
                if (second_exists && nums[i] > second) {
                    return true;
                }
                second_exists = true;
                if (nums[i] < second) {
                    second = nums[i];
                }
            }
            else {
                continue;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {20,100,10,12,5,13};
    vector<int> nums2 = {2,1,5,0,3};

    cout << sol.increasingTriplet(nums1) << endl;
    cout << sol.increasingTriplet(nums2) << endl;
    return 0;
}