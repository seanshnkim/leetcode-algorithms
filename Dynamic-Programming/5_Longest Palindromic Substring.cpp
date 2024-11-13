#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> stk;
        // Incorrect
        // vector<int> dp[s.length()];
        vector<int> dp(s.length(), 0);

        for (int i=s.length()-1; i >=0; i--) {
            if (s[i] == ')') {
                stk.push(s[i]);
            }
            // if ( s[i] = '(' )
            else {
                if (stk.empty()) {
                    dp[i] = 0;
                }
                // if stk has ')'
                else { 
                    stk.pop();
                    if (i+2 < s.length()) {
                        // Choose max between dp[i+1] and dp[i+2]
                        if (dp[i+1] > dp[i+2]) {
                            dp[i] = dp[i+1] + 2;}
                        else {
                            dp[i] = dp[i+2]+2;}}
                    else {
                        dp[i] = 2;} 
                }
            }
        }
        return dp.empty() ? 0 : *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    cout << sol.longestValidParentheses("()(())") << endl;
}