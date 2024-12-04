#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> nums) {
        int maxProd = INT_MIN;
        int product = 1;
        
        for (int num : nums){
            product *= num;
            maxProd = max(product, maxProd);
            if(product == 0) {
                product = 1;
            } 
        }

        product = 1;
        for(int i=nums.size()-1; i>=0; i--){
            product *= nums[i];
            maxProd = max(product, maxProd);
            if (product == 0) {
                product = 1;
            }
        }

        return maxProd;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2,3,-2,4};
    vector<int> nums2 = {-2, 0, 1, 3, -4 ,5};
    cout << sol.maxProduct(nums1) << endl;
    cout << sol.maxProduct(nums2) << endl;
    return 0;
}
