#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_it = 0;
        int p_it = 0;
        while (p_it < p.size() && s_it < s.size()) {
            // if normal alphabet
            if (p[p_it] == '.') {
                p_it++;
                s_it++;
            }
            else if (p[p_it] == '*') {
                if (p[p_it-1] == '.') {
                    return true;
                }
                else {
                    while (s[s_it] == p[p_it-1]) {
                        s_it++;
                    }
                }
                p_it++;
            }
            // if p[p_it] is a normal English alphabet
            else {
                if (s[s_it] == p[p_it]) {
                    p_it++;
                    s_it++;
                }
                else {
                    return false;
                }
            }
        }
        if (p_it == p.size() && s_it == s.size()) {
            return true;
        }
        else {
            return false;
        }
        
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aa", "a") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("ab", ".*") << endl;
    cout << sol.isMatch("abcceeeegddii", "ab.ce*.dd.*") << endl;
    return 0;
}