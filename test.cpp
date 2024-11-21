#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int myFunction(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Solution sol;
    int a = 0, b = 1;
    cout << sol.myFunction(a, b) << endl;
    return 0;
}