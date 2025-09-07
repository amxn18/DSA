#include <bits/stdc++.h>
using namespace std;

// LC 51. N-Queens
// TC --> O(n! * n) SC --> O(n^2 + n) for board
class Solution {
public:
    bool canFill(int row, int col, vector<string>& board, int n){
        // Need To Check Only 3 Dirs 1) upper left diagnol, 2) lower left diagnol 3) in same row on left side 
        // 1) Check upper left Diagnol
        int tempRow = row;
        int tempCol = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        // 2) Check In same Row On left side as we our filling form L to R no need to check on right side
        row = tempRow;
        col = tempCol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        // 3) Check lower left diagnol;
        row = tempRow;
        col = tempCol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true; // All Directions Checked
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){   // Trying All Columns
        if(col == n){  // All Vertical COlumns Checked
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(canFill(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';  // Unmark While BackTracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Final Ans Contains all possible chess boards
        vector<string> board(n); // Chess Board Of N Strings 
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};