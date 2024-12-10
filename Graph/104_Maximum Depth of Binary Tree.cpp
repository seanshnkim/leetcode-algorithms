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
    int maxDepth(TreeNode* root) {
        return countDepth(root, 1);
    }
    int countDepth(TreeNode* node, int depth) {
        if (node == nullptr) {
            return depth-1;
        }
        if (node->left != nullptr || node->right != nullptr) {
            return max(countDepth(node->left, depth+1), countDepth(node->right, depth+1) );
        }
        else {
            return depth;
        }
    }
};