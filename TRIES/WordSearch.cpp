#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    string word;
    TrieNode() {
        fill(begin(children), end(children), nullptr);
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty()) return result;
        
        // Build the Trie
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->word = word;  // Mark the end of a word
        }
        
        int m = board.size(), n = board[0].size();
        
        // Backtracking function
        function<void(int, int, TrieNode*)> dfs = [&](int i, int j, TrieNode* node) {
            char c = board[i][j];
            if (c == '#' || !node->children[c - 'a']) return;  // Out of bounds or already visited
            node = node->children[c - 'a'];
            
            if (!node->word.empty()) {
                result.push_back(node->word);
                node->word = "";  // Avoid duplicate words
            }
            
            // Mark the current cell as visited
            board[i][j] = '#';
            
            // Explore all 4 possible directions (up, down, left, right)
            if (i > 0) dfs(i - 1, j, node);  // Up
            if (i < m - 1) dfs(i + 1, j, node);  // Down
            if (j > 0) dfs(i, j - 1, node);  // Left
            if (j < n - 1) dfs(i, j + 1, node);  // Right
            
            // Unmark the current cell after exploration
            board[i][j] = c;
        };
        
        // Start backtracking from every cell in the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, root);
            }
        }
        
        return result;
    }
};
