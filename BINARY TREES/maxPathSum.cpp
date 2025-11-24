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

// LC 124
// TC O(N) SC O(N)
class Solution {
public:
    int maxSum;
    int solve(TreeNode* node){
        if(node == NULL) return 0;
        int l = solve(node->left);
        int r = solve(node->right);

        int c1 = l + r + node->val;
        int c2 = max(l, r) + node->val;
        int c3 = node->val;

        maxSum = max({maxSum, c1, c2, c3});
        return max(c2, c3);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};