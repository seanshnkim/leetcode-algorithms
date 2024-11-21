#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int buy = prices[0], sell = 0;
        vector<int> profits(N, 0);
        profits[0] = -1 * buy;

        for (int i = 1; i < prices.size(); i++) {
            sell = prices[i];
            int cur_profit = profits[i-1] + sell;
            if (cur_profit <= 0) {
                buy = prices[i];
                profits[i] = -1 * buy;
            }
            else {
                profits[i] = cur_profit;
            }
        }
        return profits[N-1];
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}