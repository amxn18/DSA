#include <bits/stdc++.h>
using namespace std;

// LC 111
// DFS 


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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int l = root->left != NULL ? minDepth(root->left) : INT_MAX;
        int r = root->right != NULL ? minDepth(root->right) : INT_MAX;

        return 1 + min(l, r);
    }
};

// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left == NULL && node->right == NULL) return depth;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};