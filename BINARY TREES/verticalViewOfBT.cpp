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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mp; // {line, node->data}
        queue<pair<Node*, int>> q; // {node, line}
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            if(mp.find(line) == mp.end()) mp[line] = node->data;
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};