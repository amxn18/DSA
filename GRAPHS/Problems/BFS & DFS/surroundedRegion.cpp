#include <bits/stdc++.h>
using namespace std;

// LC 130. Surrounded Regions
// TC O(m*n) SC O(m*n)

class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0,1}};
    void DFS(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& board){
        visited[i][j] = 1; // Mark
        int m = board.size();
        int n = board[0].size();
        for(auto dir : dirs){
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && !visited[newI][newJ] && board[newI][newJ] == 'O') DFS(newI, newJ, visited, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // First Row And Last Row 
        for(int j=0; j<n; j++){
            if(!visited[0][j] && board[0][j] == 'O') DFS(0, j, visited, board); // First Row
            if(!visited[m-1][j] && board[m-1][j] == 'O') DFS(m-1, j, visited, board); // Last Row
        }
        // First Column and last Column
        for(int i = 0; i<m; i++){
            if(!visited[i][0] && board[i][0] == 'O') DFS(i, 0, visited, board); // First Column
            if(!visited[i][n-1] && board[i][n-1] == 'O') DFS(i, n-1, visited, board); // Last Column
        }
        // Convert Surrounded 'O'
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};