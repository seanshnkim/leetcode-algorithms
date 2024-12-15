#include <vector>
#include <deque>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) {
            return res;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int qSize = q.size();
            
            vector<int> curLevelNodes;
            while(qSize--) {
                TreeNode* node;
                if (!leftToRight) { // rightToLeft
                    node = q.back();
                    q.pop_back();
                }
                else { // leftToRight
                    node = q.front();
                    q.pop_front();
                }
                if (!node) {
                    continue;
                }
                curLevelNodes.push_back(node->val);

                if (!leftToRight) { // rightToLeft
                    q.push_front(node->right);
                    q.push_front(node->left);
                }
                else { // leftToRight
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
            }
            if (!curLevelNodes.empty()) {
                res.push_back(curLevelNodes);
            }
            leftToRight = !leftToRight;
        }
        return res;
    }
};