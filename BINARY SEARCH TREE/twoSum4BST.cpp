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

// LC 653. Two Sum IV - Input is a BST
// TC - O(N) , SC - O(N)
class Solution {
public:
    vector<int> inorder;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int n = inorder.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            int sum = inorder[l] + inorder[r];
            if(sum > k) r--;
            else if(sum < k) l++;
            else return true;
        }
        return false;
    }
};