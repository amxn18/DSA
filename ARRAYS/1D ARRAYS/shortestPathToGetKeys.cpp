#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Possible directions: down, up, right, left
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
        int shortestPathAllKeys(vector<string>& grid) {
            int m = grid.size();         // Number of rows
            int n = grid[0].size();      // Number of columns
    
            queue<vector<int>> q;        // Format: {i, j, steps, keyStatus}
            int keyCount = 0;            // Total keys in the grid
    
            // Locate the start point '@' and count total number of keys
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '@') {
                        q.push({i, j, 0, 0}); // Starting position
                    } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                        keyCount++;
                    }
                }
            }
    
            // All keys collected when bitmask reaches this value
            int allKeysStatus = (1 << keyCount) - 1;
    
            // Visited array with dimensions [rows][cols][keyStatus]
            int visited[m][n][allKeysStatus + 1];
            memset(visited, 0, sizeof(visited));
    
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
                int i = temp[0];
                int j = temp[1];
                int steps = temp[2];
                int status = temp[3];
    
                // If all keys are collected
                if (status == allKeysStatus) return steps;
    
                // Try moving in all four directions
                for (auto& dir : dirs) {
                    int I = i + dir[0];
                    int J = j + dir[1];
    
                    if (I >= 0 && I < m && J >= 0 && J < n && grid[I][J] != '#') {
                        char ch = grid[I][J];
    
                        // Lock: check if we have the corresponding key
                        if (ch >= 'A' && ch <= 'F') {
                            if (visited[I][J][status] == 0 && ((status >> (ch - 'A')) & 1)) {
                                visited[I][J][status] = 1;
                                q.push({I, J, steps + 1, status});
                            }
                        }
                        // Key: update keyStatus bitmask
                        else if (ch >= 'a' && ch <= 'f') {
                            int newStatus = status | (1 << (ch - 'a'));
                            if (visited[I][J][newStatus] == 0) {
                                visited[I][J][newStatus] = 1;
                                q.push({I, J, steps + 1, newStatus});
                            }
                        }
                        // Empty cell or start cell
                        else {
                            if (visited[I][J][status] == 0) {
                                visited[I][J][status] = 1;
                                q.push({I, J, steps + 1, status});
                            }
                        }
                    }
                }
            }
    
            return -1; // No valid path found
        }
    };
    

// # LeetCode 864. Shortest Path to Get All Keys
// ##  Problem Explanation:
// You're given a 2D grid representing a maze. The grid contains:
// - `@` → your starting position  
// - `.` → empty cell  
// - `#` → wall  
// - `a-f` → keys  
// - `A-F` → locks (each lock needs its corresponding key to be opened)

// Goal: Starting from `@`, collect all keys in the **minimum number of moves**. You can move in 4 directions and cannot pass through walls or locks without their keys.

// ---

// ##  Approach:
// - Use **BFS** since we need the shortest path.
// - Maintain a `status` bitmask to track the keys collected so far.
// - Use a 3D `visited[i][j][status]` array to avoid revisiting same cell with same keys.
// - For each cell:
//   - If it's a **key**, update the `status`.
//   - If it's a **lock**, check if the corresponding key is present in `status`.
//   - If `status` equals `2^k - 1` (all keys collected), return the number of steps taken.

// ---

// ## Data Structures Used:
// - `queue<vector<int>>` for BFS traversal
// - 3D `visited` array to prevent revisiting states

// ---

// ##  Time Complexity:
// - `O(m * n * 2^k)` where:
//   - `m` and `n` are grid dimensions
//   - `k` is number of keys (max 6, so 2^k = 64 max states)
// - BFS visits each cell-state combination at most once

// ---

// ##  Space Complexity:
// - `O(m * n * 2^k)` due to the `visited` 3D array and BFS queue

// ---


