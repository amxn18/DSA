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

// LC 662
// TC: O(N), SC: O(W) where W is the maximum width of the
class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll maxWidth = 0;
        while(!q.empty()){
            ll Lmost = q.front().second;
            ll Rmost = q.back().second;
            maxWidth = max(maxWidth, Rmost - Lmost + 1);
            int n = q.size();
            while(n--){
                TreeNode* node = q.front().first;
                ll idx = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, 2*idx+1});
                if(node->right) q.push({node->right,2*idx+2});
            }
        }
        return maxWidth;
    }
};