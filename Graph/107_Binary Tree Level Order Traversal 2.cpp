#include <algorithm>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        vector<int> curLevNodes;
        q.push(root);
        
        while (!q.empty()) {
            int qSize = q.size();
            curLevNodes.clear();

            while (qSize--) {
                TreeNode* node = q.front();
                q.pop();

                if (!node) {
                    continue;
                }
                curLevNodes.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if (!curLevNodes.empty()) {
                res.push_back(curLevNodes);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}