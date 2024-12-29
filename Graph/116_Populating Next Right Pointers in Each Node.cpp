#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node* createPerfectBinaryTree(const vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        Node* current = q.front();
        q.pop();

        if (i < arr.size()) {
            current->left = new Node(arr[i++]);
            q.push(current->left);
        }

        if (i < arr.size()) {
            current->right = new Node(arr[i++]);
            q.push(current->right);
        }
    }

    return root;
}

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {return NULL;}
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int qSize = q.size();

            Node* prevNode = q.front();
            q.pop();
            qSize--;
            if (prevNode->left && prevNode->right) {
                q.push(prevNode->left);
                q.push(prevNode->right);
            }
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
    vector <int> root_vector = {1,2,3,4,5,6,7};
    Node* root = createPerfectBinaryTree(root_vector);
    Node* root_result = sol.connect(root);
    return 0;
}