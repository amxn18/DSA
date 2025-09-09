#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool solve(vector<vector<char>>& board){
        int n = board.size();  // rows
        int m = board[0].size(); // columns
        // Traversing in Board to find Empty Cell
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c<='9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board)==true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            // Check Each Row
            if(board[i][col] == c) return false;
            // Check Each Column
            if(board[row][i] == c) return false;
            // Check Each 3x3
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};