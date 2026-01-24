#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// TC = O(N), SC = O(N)
class Solution {
  public:
    unordered_map<Node*, Node*> parent;
    Node* targetNode = NULL;
    void inorder(Node* root, int target){
        if(!root) return;
        if(root->data == target) targetNode = root;
        if(root->left) parent[root->left] = root;
        inorder(root->left, target);
        if(root->right) parent[root->right] = root;
        inorder(root->right, target);
    }
    int BFS(Node* target){
        queue<Node*> q;
        q.push(target);
        unordered_set<Node*> visited;
        visited.insert(target);
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            bool burned = false;
            while(n--){
                Node* curr = q.front();
                q.pop();
                
                // Left
                if(curr->left && !visited.count(curr->left)){
                    burned = true;
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                
                // Right
                if(curr->right && !visited.count(curr->right)){
                    burned = true;
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                
                // Parent
                if(parent[curr] && !visited.count(parent[curr])){
                    burned = true;
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            if(burned == true) time++;
        }
        return time;
    } 
    
    int minTime(Node* root, int target) {
        inorder(root, target);
        return BFS(targetNode);
    }
};