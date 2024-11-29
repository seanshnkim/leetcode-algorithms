#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

/*
Takeaway: Don't make the problem complicated. Sometimes the only solution is so simple and naive (and may be the best)
-> For this problem, just sort `nums` !
*/

class Solution
{
public:
    void wiggleSort(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int k = 0;
        vector<int> nums_copy(nums);
        for (int i=2; i < N; i+=2) {
            nums_copy[i] = nums[i/2];
        }
        for (int i=1; i < N; i+=2) {
            nums_copy[i] = nums[N-((i+1)/2)];
        }
        nums = nums_copy;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,5,5,4,4,4,4};
    sol.wiggleSort(nums);
    
    cout << "[";
    for (auto i: nums) {
        cout << i << ", ";
    }
    cout << "]" << endl;


}