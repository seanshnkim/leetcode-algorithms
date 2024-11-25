#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void wiggleSort(vector<int>& nums) {
        int N = nums.size();
        for (int i=0; i < N-1; i++) {
            if ( (i % 2 == 0 && nums[i] > nums[i+1]) \
            || (i % 2 == 1 && nums[i] < nums[i+1]) ) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {6, 5, 4, 3, 2, 1};
    sol.wiggleSort(nums);
    for (const auto &num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}