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

// LC 257 
// TC: O(N), SC: O(H) where H is the height of the tree
class Solution {
public:
    void solve(TreeNode* node, vector<string>& ans, string path){
        if(!node) return;
        path += to_string(node->val);
        if(!node->left && !node->right){
            ans.push_back(path);
            return;
        }
        path += "->";
        solve(node->left, ans, path);
        solve(node->right, ans, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, ans, "");
        return ans;
    }
};