#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numOcc;
        unordered_set<int> occurrences;
        
        // Count occurrences
        for (int num : arr) {
            numOcc[num]++;
        }
        
        // Check for unique occurrences
        for (const auto& [num, count] : numOcc) {
            if (!occurrences.insert(count).second) {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1,2,2,1,1,3};
    cout << sol.uniqueOccurrences(arr) << endl;
    return 0;
}