#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stk;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    // int start = 0;
                    int start = -1; // for the very first part: What if s = `()`?
                    if (!stk.empty() ) {
                        start = stk.top();
                    }
                    maxLen = max(maxLen, i - start);
                } else {
                    stk.push(i);
                }
            }
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << sol.longestValidParentheses("()") << endl;
    return 0;
}