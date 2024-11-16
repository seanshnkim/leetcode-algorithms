#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(std::string text, std::string pattern) {
        int m = text.length();
        int n = pattern.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;
        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                bool first_match = (i < m) && (pattern[j] == text[i] || pattern[j] == '.');
                if (j + 1 < n && pattern[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aaa", "a*a") << endl;
    cout << sol.isMatch("a", "ab*") << endl;
    cout << sol.isMatch("aab", "c*a*b") << endl;
    // cout << sol.isMatch("ab", ".*c") << endl;
    // cout << sol.isMatch("aa", "a*") << endl;
    // cout << sol.isMatch("ab", ".*") << endl;
    // cout << sol.isMatch("abcceeeegddii", "ab.ce*.dd.*") << endl;
    return 0;
}