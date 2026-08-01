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

// Preorder(Root-Left-Right) Traversal Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            result.push_back(node->val);
        }
        return result;
    }
};

// Inorder(Left-Root-Right) Traversal Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};

// Postorder(Left-Right-Root) Traversal Iterative (Using 2 Stacks)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<int> ans;
        if(root == NULL) return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        } 
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

// Postorder(Left-Right-Root) Traversal Iterative (Using 1 Stack)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* rightNode = st.top()->right;
                if (rightNode == NULL) {
                    TreeNode* temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = rightNode;
                }
            }
        }

        return ans;
    }
};
