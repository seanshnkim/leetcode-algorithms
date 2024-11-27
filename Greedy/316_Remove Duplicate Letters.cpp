#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // alphabet has 26 characters
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!seen[c - 'a']) {
                while (!st.empty() && c < st.top() && i < lastIndex[st.top() - 'a']) {
                    seen[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(c);
                seen[c - 'a'] = true;
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "bcabc";
    cout << sol.removeDuplicateLetters(s) << endl;
    return 0;
}