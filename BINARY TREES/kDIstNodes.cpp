#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// LC 863. All Nodes Distance K in Binary Tree
// TC = O(N), SC = O(N)
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root) {
        if (!root) return;

        if (root->left) parent[root->left] = root;
        inorder(root->left);

        if (root->right) parent[root->right] = root;
        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        while (!q.empty()) {
            int n = q.size();
            if (k == 0) break;

            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                // left
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                // right
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                // parent
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            k--;
        }

        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);
        BFS(target, k, result);
        return result;
    }
};
