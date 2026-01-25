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

// LC 105: Construct Binary Tree from Preorder and Inorder Traversal
// TC = O(N^2), SC = O(N)
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int s, int e, int& idx){
        if(s>e) return NULL;
        int rootVal = preorder[idx];
        int i = s;
        for(; i<=e; i++){
            if(inorder[i] == rootVal) break;
        }
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, s, i-1, idx);
        root->right = solve(preorder, inorder, i+1, e, idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};