#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!isBalanced(root->left) || !isBalanced(root->right)) {
            return false;
        }
        return abs(dfs(root->left, 1) - dfs(root->right, 1)) <= 1;
    }

    int dfs(TreeNode* root, int depth) {
        if (!root) {
            return depth-1;
        }
        return max(dfs(root->left, depth+1), dfs(root->right, depth+1) );
    }
};

int main()
{
    Solution sol;
    TreeNode root;
    cout << sol.isBalanced(&root) << endl;
    return 0;
}