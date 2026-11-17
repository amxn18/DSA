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

        // Step 1: If the child sum is greater than the root value, update the root value to the child sum.
        if(child >= root->val) root->val = child;
        else{
            if(root->left) root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }
        // Step 2: Recursively call the function for the left and right subtrees.
        changeToChildrenSum(root->left);
        changeToChildrenSum(root->right);

        // Step 3: After the recursive calls, update the root value to the sum of its children.

        int totalOfChildren = 0;
        if(root->left) totalOfChildren += root->left->val;
        if(root->right) totalOfChildren += root->right->val;
        if(root->left || root->right) root->val = totalOfChildren;
    }
};

class Solution {
  public:
    bool isSumProperty(TreeNode *root) {
        if(root == NULL) return true;
        if(root -> left == NULL && root -> right == NULL) return true;
        int childSum = 0;
        if(root->left) childSum += root->left->val;
        if(root->right) childSum += root->right->val;
        if(childSum != root->val) return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};