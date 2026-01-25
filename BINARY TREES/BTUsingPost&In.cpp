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

// LC 106
// TC = O(N^2), SC = O(N)
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int s, int e, int& idx){
        if(s>e) return NULL;
        int rootVal = postorder[idx];

        int i = s;
        for(; i<=e; i++){
            if(inorder[i] == rootVal) break;
        }

        idx--;
        TreeNode* root = new TreeNode(rootVal);
        // Build Right Child first 
        
        root->right = solve(inorder, postorder, i+1, e, idx);
        root->left = solve(inorder, postorder, s, i-1, idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return solve(inorder, postorder, 0, n-1, idx);
    }
};