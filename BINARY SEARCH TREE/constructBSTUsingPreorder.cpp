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

// LC 1008 
// Method 1: TC: O(NlogN) + O(N), SC: O(N)
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int s, int e, int& idx){
        if(s>e) return NULL;
        int rootVal = preorder[idx];
        int i = s;
        for(; i<=e; i++){
            if(inorder[i] == rootVal) break;
        }
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = construct(preorder, inorder, s, i-1, idx);
        root->right = construct(preorder, inorder, i+1, e, idx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder; 
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();
        int idx = 0;
        return construct(preorder, inorder, 0, n-1, idx);
    }
};

// Method 2: TC: O(N), SC: O(N)
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, int& i, int bound){
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = construct(preorder, i, root->val);
        root->right = construct(preorder, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return construct(preorder, i, INT_MAX);
    }
};