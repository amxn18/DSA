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

// LC 450 TC: O(H) SC: O(1)
class Solution {
public:
    TreeNode* find(TreeNode* root){
        if(root->right == NULL) return root;
        return find(root->right);
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = find(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key)
            return helper(root);

        TreeNode* curr = root;

        while(root){   // ✅ FIX HERE
            if(key < root->val){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                root = root->left;
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                root = root->right;
            }
        }
        return curr;
    }
};
