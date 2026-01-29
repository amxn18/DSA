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

// LC 98: Validate Binary Search Tree TC - O(N), SC - O(H)
class Solution {
public:
    bool validate(TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};