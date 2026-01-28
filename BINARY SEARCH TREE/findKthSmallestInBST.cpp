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
// LC 230
// Method 1 TC O(N) + O(NlogN) SC O(N)
class Solution {
public:
    void DFS(TreeNode* root, vector<int>& store){
        if(root == NULL) return;
        DFS(root->left, store);
        store.push_back(root->val);
        DFS(root->right, store);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> store;
        DFS(root, store);
        sort(store.begin(), store.end());
        return store[k-1];
    }
};

// Method 2 TC O(H + k) SC O(H)
class Solution {
public:
    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if (!root || ans != -1) return;
        inorder(root->left, k);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};