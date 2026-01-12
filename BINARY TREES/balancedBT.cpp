#include <bits/stdc++.h>
using namespace std;

// DFS TC O(N) SC O(N)
// LC 110
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Brute TC O(N^2) SC O(H)
class Solution {
public:
    int findHt(TreeNode* node){
        if(node == NULL) return 0;
        int lh = findHt(node->left);
        int rh = findHt(node->right);
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh = findHt(root->left);
        int rh = findHt(root->right);

        if(abs(lh-rh) > 1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;
        return true;
    }
};

// Optimal TC O(N) SC O(H)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    int check(TreeNode* root){
        if(root == NULL) return 0;
        int lh = check(root->left);
        if(lh == -1) return -1;
        int rh = check(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
};