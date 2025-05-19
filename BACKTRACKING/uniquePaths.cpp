#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        int m, n;
        int result; // Stores the count of unique paths
        int nonObstacles; // Total count of non-obstacle cells that must be visited
        vector<vector<int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}}; // Directions for movement (down, up, right, left)
    
        void bt(vector<vector<int>>& grid, int count, int i, int j) {
            // Base cases to stop recursion
            if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return; // Out of bounds or obstacle
            
            if(grid[i][j] == 2) { // Reached the ending square
                if(count == nonObstacles) { // If all non-obstacle squares are visited exactly once
                    result++; 
                }
                return; 
            }
    
            // Mark the cell as visited to avoid revisiting
            grid[i][j] = -1; 
    
            // Explore all 4 possible directions
            for(auto& dir : dirs) {
                int newI = i + dir[0];
                int newJ = j + dir[1];
                bt(grid, count + 1, newI, newJ);
            }
    
            // Backtrack by unmarking the cell
            grid[i][j] = 0;
        }
    
        int uniquePathsIII(vector<vector<int>>& grid) {
            m = grid.size(); // Number of rows
            n = grid[0].size(); // Number of columns
            result = 0;
            nonObstacles = 0;
            int startX = 0, startY = 0; // Starting position
    
            // Count non-obstacle cells and find the starting position
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) { 
                    if(grid[i][j] == 0) {
                        nonObstacles++; // Count empty squares
                    }
                    if(grid[i][j] == 1) { // Identify start position
                        nonObstacles++; // Include the start cell in non-obstacles
                        startX = i;
                        startY = j;
                    }
                }
            }
    
            // Start backtracking from the starting position
            bt(grid, 0, startX, startY);
            return result;
        }
    };
    // # Algorithm Explanation:

    // # 1. Define the class Solution with helper variables:
    // #    - m, n -> dimensions of the grid.
    // #    - result -> stores the final count of valid paths.
    // #    - nonObstacles -> count of non-obstacle cells to be visited.
    // #    - dirs -> possible movement directions (down, up, right, left).
    
    // # 2. Function: bt (Backtracking)
    // #    - Takes the current position (i, j), and count of visited cells.
    // #    - If out of bounds or encounters an obstacle (-1), return.
    // #    - If it reaches the target (2), check if all non-obstacles were visited.
    // #      - If yes, increment result.
    // #    - Mark the cell as visited (-1) and move in all four possible directions.
    // #    - Backtrack by restoring the cell to 0.
    
    // # 3. Function: uniquePathsIII
    // #    - Initialize grid size and variables.
    // #    - Identify the starting position and count non-obstacle cells.
    // #    - Call the backtracking function from the start position.
    // #    - Return the total count of valid paths.
    
    // # Complexity:
    // # - Time Complexity: O(3^(mn)) worst case, as we explore 4 directions at each step.
    // # - Space Complexity: O(mn) due to recursion depth.
        