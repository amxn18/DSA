#include <bits/stdc++.h>
using namespace std;

// LC 102
// TC: O(N), SC: O(N)


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root == NULL) return result;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> eachLevel;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                eachLevel.push_back(node->val);
            }
            result.push_back(eachLevel);
        }
        return result;
    }
};