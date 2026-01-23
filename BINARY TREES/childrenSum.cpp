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
class Solution {
public:
    void changeToChildrenSum(TreeNode* root){
        if(root == NULL) return;
        int child = 0;
        if(root->left) child += root->left->val;
        if(root->right) child += root->right->val;

        if(child >= root->val) root->val = child;
        else{
            if(root->left) root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }

        changeToChildrenSum(root->left);
        changeToChildrenSum(root->right);

        int totalOfChildren = 0;
        if(root->left) totalOfChildren += root->left->val;
        if(root->right) totalOfChildren += root->right->val;
        if(root->left || root->right) root->val = totalOfChildren;
    }
};

class Solution {
public:
    bool isSumProperty(TreeNode* root) {
        if (!root) return true;

        if (!root->left && !root->right)
            return true;

        int childSum = 0;
        if (root->left)  childSum += root->left->val;
        if (root->right) childSum += root->right->val;

        if (root->val != childSum)
            return false;

        return isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
};