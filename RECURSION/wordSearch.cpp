#include <bits/stdc++.h>
using namespace std;

// LC 79. Word Search
// TC --> O(m*n*4^l) l -- length of word
// SC --> O(l) for recursion stack
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word){
        if(idx == word.length()) return true;
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j]; // Store Current Posi
        board[i][j] = '#'; // Mark Visit;
        for(auto& dir : dirs){  // Visit all 4 dirs
            int newI = i + dir[0];
            int newJ = j + dir[1];
            if(find(board, newI, newJ, idx+1, word)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && find(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};