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

// Preorder Traversal: Root -> Left -> Right
class Solution {
public:
    void preorder(TreeNode* node, vector<int>& result){
        if(node == NULL) return;
        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};

// Inorder Traversal: Left -> Root -> Right
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& result){
        if(node == NULL) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

// Postorder Traversal: Left -> Right -> Root
class Solution {
public:
    void postorder(TreeNode* node, vector<int>& result){
        if(node == NULL) return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};