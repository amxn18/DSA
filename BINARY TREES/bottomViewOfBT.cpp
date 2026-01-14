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

// TC = O(NlogN), SC = O(N)
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            mp[line] = node->data; // Update node on each line with latest or last node 
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        for (auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};