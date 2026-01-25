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
    int solve(TreeNode* root, int& ctr){
        if(root == NULL) return 0;
        ctr++;
        solve(root->left, ctr);
        solve(root->right, ctr);
        return ctr;
    }
    int countNodes(TreeNode* root) {
        int ctr = 0;
        return solve(root, ctr);
    }
};