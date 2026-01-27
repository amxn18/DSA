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

int min(TreeNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->val;
}

int max(TreeNode* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->val;
}