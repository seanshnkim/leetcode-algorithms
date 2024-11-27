#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>

using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> candies(N, 1);
        stack<int> st;

        for (int i = 0; i < N-1; i++) {
            if (ratings[i] > ratings[i+1]) {
                st.push(i+1);
            }
            else {
                while (!st.empty()) {
                    int idx = st.top();
                    if (candies[idx-1] <= candies[idx]) {
                        candies[idx-1] = candies[idx]+1;
                    }
                    st.pop();
                }
                if (ratings[i] < ratings[i+1]) {
                    candies[i+1] = candies[i] + 1;
                }
            }
        }
        while (!st.empty()) {
            int idx = st.top();
            if (candies[idx-1] <= candies[idx]) {
                candies[idx-1] = candies[idx]+1;
            }
            st.pop();
        }
        return reduce(candies.begin(), candies.end());
    }
};

int main()
{
    Solution sol;
    vector<int> ratings1 = {1,0,2};
    vector<int> ratings2 = {1,2,2};
    vector<int> ratings3 = {1,2,87,87,87,2,1};
    vector<int> ratings4 = {1,3,4,5,2};

    cout << sol.candy(ratings1) << endl;
    cout << sol.candy(ratings2) << endl;
    cout << sol.candy(ratings3) << endl;
    cout << sol.candy(ratings4) << endl;
    
    return 0;
}