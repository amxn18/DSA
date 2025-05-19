#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:  
        int m, n;  
        // Directions for moving in 4 possible ways (down, up, right, left)
        vector<vector<int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}};  
        
        // Recursive function to search for the word in the board using DFS
        bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {
            // If we have found all characters of the word, return true
            if(idx == word.length())  
                return true;
    
            // If out of bounds, visited ('#'), or character does not match, return false
            if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' || board[i][j] != word[idx])  
                return false;
    
            // Temporarily mark the cell as visited
            char temp = board[i][j];  
            board[i][j] = '#';  
    
            // Explore all four directions
            for(auto& dir : dirs) {
                int newI = i + dir[0];  // Move in row direction
                int newJ = j + dir[1];  // Move in column direction
    
                // If any path leads to the word, return true
                if(find(board, newI, newJ, idx + 1, word)) 
                    return true;
            }
    
            // Restore the cell before backtracking
            board[i][j] = temp;  
            return false;
        }
    
        // Main function to check if the word exists in the board
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();    // Get number of rows
            n = board[0].size(); // Get number of columns
    
            // Iterate over all cells in the board
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    // If first character matches, start backtracking search
                    if(board[i][j] == word[0] && find(board, i, j, 0, word))  
                        return true;
                }
            }
            return false;  // Return false if the word is not found
        }
    };
    
//     # Word Search (Leetcode 79) - Backtracking Approach
// # -------------------------------------------------
// # 1. We check if a given word exists in a 2D board by searching for it in all four directions.
// # 2. We use a helper function `find()` that performs recursive DFS with backtracking.
// # 3. We maintain a `dirs` vector for four possible movements: right, left, down, and up.
// # 4. To avoid revisiting the same cell, we temporarily mark it as `#` and restore it after recursion.
// # 5. If we reach the end of the word (idx == word.length()), return true.
// # 6. If we go out of bounds, revisit a marked cell, or find a mismatch, return false.
// # 7. If any path leads to a solution, return true immediately.
// # 8. Restore the board before backtracking to explore other paths.
// # 9. The main function `exist()` iterates over all board cells and calls `find()` when the first character matches.
// # 10. If `find()` returns true for any path, return true; otherwise, return false.

// # Time Complexity: O(m * n * 4^L)  (L = length of word, 4 choices per step)
// # Space Complexity: O(L) (recursion depth of call stack)
