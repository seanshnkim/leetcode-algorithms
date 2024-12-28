#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int qSize = q.size();

            Node* prevNode = q.front();
            q.pop();
            qSize--;
            while (qSize--) {
                Node* curNode = q.front();
                q.pop();
                prevNode->next = curNode;

                // Because it's given as perfect binary tree
                if (curNode->left && curNode->right) {
                    q.push(curNode->left);
                    q.push(curNode->right);
                }
                prevNode = curNode;
            }
            // if (!prevNode->next) {
            //     prevNode->next = NULL;
            // }
        }
        return root;
    }
};

int main()
{
    Solution sol;
    // cout << sol.connect() << endl;
    return 0;
}