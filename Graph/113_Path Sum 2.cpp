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
    // The function definition
    void recurseTree(TreeNode* node, int remainingSum, vector<int>& pathNodes,
                     vector<vector<int>>& pathsList) {
        if (!node) {
            return;
        }
        pathNodes.push_back(node->val);

        if (remainingSum == node->val && !node->left && !node->right) {
            pathsList.push_back(vector<int>(pathNodes));
        }
        else {
            this->recurseTree(node->left, remainingSum - node->val, pathNodes,
                              pathsList);
            this->recurseTree(node->right, remainingSum - node->val, pathNodes,
                              pathsList);
        }
        pathNodes.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> pathsList;
        vector<int> pathNodes;
        this->recurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
    }
};

int main()
{
    Solution sol;
    TreeNode* root;
    int targetSum = 22;
    // sol.pathSum(root, targetSum);
    return 0;
}