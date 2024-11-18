#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    struct CompareFirst {
        bool operator()(const pair<int, int>& value, int key) {
            return value.first < key;
        }
        bool operator()(int key, const pair<int, int>& value) {
            return key < value.first;
        }
    };
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> diffs;
        for (int i=0; i < nums.size(); ++i) {
            diffs.push_back({target - nums[i], i});
        }
        sort(diffs.begin(), diffs.end());
        vector<int> ans = {-1, -1};
        
        for (int i=0; i < nums.size(); ++i) {
            if ( binary_search(diffs.begin(), diffs.end(), nums[i], CompareFirst()) ) {
                auto found = lower_bound(diffs.begin(), diffs.end(), nums[i], CompareFirst());
                if (found != diffs.end() && found->first == nums[i] && found->second != i) {
                    ans[0] = i;
                    ans[1] = found->second;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}