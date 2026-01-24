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

// LC 2385. Amount of Time for Binary Tree to Be Infected
// TC -> O(N), SC -> O(N)
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* startNode = NULL;

    void inorder(TreeNode* root, int start){
        if(!root) return;
        if(root->val == start) startNode = root;

        if(root->left) parent[root->left] = root;
        inorder(root->left, start);
        if(root->right) parent[root->right] = root;
        inorder(root->right, start);
    }

    int BFS(TreeNode* start){
        queue<TreeNode*> q;
        q.push(start);
        unordered_set<TreeNode*> visited;
        visited.insert(start);

        int time = 0;
        while(!q.empty()){
            int n = q.size();
            bool infected = false;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                // Left
                if(curr->left && !visited.count(curr->left)){
                    infected = true;
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                // Right
                if(curr->right && !visited.count(curr->right)){
                    infected = true;
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                // Parent
                if(parent[curr] && !visited.count(parent[curr])){
                    infected = true;
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            if(infected == true) time++;
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        inorder(root, start);
        return BFS(startNode);
    }
};