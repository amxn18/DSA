#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    bool isLeaf(Node* node){
        return !node->left && !node->right;
    }
    
    void addLeftBoundary(Node* node, vector<int>& result){
        Node* curr = node->left;
        while(curr){
            if(!isLeaf(curr)) result.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addRightBoundary(Node* node, vector<int>& result){
        Node* curr = node->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr))temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i = temp.size()-1; i>=0; i--){
            result.push_back(temp[i]);
        }
    }
    
    void addLeaves(Node* node, vector<int>& result){
        if(isLeaf(node)){
            result.push_back(node->data);
            return;
        }
        if(node->left) addLeaves(node->left, result);
        if(node->right) addLeaves(node->right, result);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        if(root == NULL) return result;
        if(!isLeaf(root)) result.push_back(root->data);
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);
        return result;
    }
};