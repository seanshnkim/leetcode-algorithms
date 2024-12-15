#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        return min_dfs(root, 1);
    }
    int min_dfs(TreeNode *node, int depth) {
        if (!node) {
            return depth-1;
        }
        if (!node->left && !node->right) {
            return depth;
        }
        else if (!node->left) {
            return min_dfs(node->right, depth+1);
        }
        else if (!node->right) {
            return min_dfs(node->left, depth+1);
        }
        else {
            return min(min_dfs(node->left, depth+1), min_dfs(node->right, depth+1) );
        }
    }
    
};

int main()
{
    Solution sol;
    cout << sol.myFunction() << endl;
    return 0;
}