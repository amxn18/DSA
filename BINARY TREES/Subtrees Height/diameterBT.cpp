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

// LC 543
// TC O(N) SC O(N)
class Solution {
public:
    int solve(TreeNode* root, int& result){
        if(root == NULL) return 0;
        int l = solve(root->left, result);
        int r = solve(root->right, result);
        result = max(result, l+r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};