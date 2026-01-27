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

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        while(root){
            if(root->data == x){
                ceil = root->data;
                return ceil;
            }
            if(x > root->data) root = root->right;
            else{
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};
