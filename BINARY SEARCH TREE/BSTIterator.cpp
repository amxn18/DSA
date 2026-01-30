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

// LC 173. Binary Search Tree Iterator
// Method 1: TC -O(1) , SC - O(N)
class BSTIterator {
public:
    vector<int> inorder;
    int idx = 0;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return inorder[idx++];
    }
    
    bool hasNext() {
        return idx < inorder.size();
    }
};

// Method 2: TC - O(1) , SC - O(H)
class BSTIterator {
public:
    stack<TreeNode*> st;
    void push(TreeNode* node){
        for(; node != NULL; node = node->left){
            st.push(node);
        }
    }
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode* nextNode = st.top();
        st.pop();
        push(nextNode->right);
        return nextNode->val;
    }
    
    bool hasNext() {
        if(st.empty() == true)  return false;
        else return true;
    }
};
