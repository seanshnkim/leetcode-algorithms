#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_num = INT_MAX;
        int second_num = INT_MAX;
        
        for (int n : nums) {
            if (n <= first_num) {
                first_num = n;
            } else if (n <= second_num) {
                second_num = n;
            } else {
                return true;
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