#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
        int shortestPathAllKeys(vector<string>& grid) {
            int m = grid.size();         
            int n = grid[0].size();     
    
            queue<vector<int>> q;        
            int keyCount = 0;            
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '@') {
                        q.push({i, j, 0, 0}); 
                    } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                        keyCount++;
                    }
                }
            }
    
            int allKeysStatus = (1 << keyCount) - 1;

            int visited[m][n][allKeysStatus + 1];
            memset(visited, 0, sizeof(visited));
    
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
                int i = temp[0];
                int j = temp[1];
                int steps = temp[2];
                int status = temp[3];
    

                if (status == allKeysStatus) return steps;

                for (auto& dir : dirs) {
                    int I = i + dir[0];
                    int J = j + dir[1];
    
                    if (I >= 0 && I < m && J >= 0 && J < n && grid[I][J] != '#') {
                        char ch = grid[I][J];
    
                        
                        if (ch >= 'A' && ch <= 'F') {
                            if (visited[I][J][status] == 0 && ((status >> (ch - 'A')) & 1)) {
                                visited[I][J][status] = 1;
                                q.push({I, J, steps + 1, status});
                            }
                        }
                        
                        else if (ch >= 'a' && ch <= 'f') {
                            int newStatus = status | (1 << (ch - 'a'));
                            if (visited[I][J][newStatus] == 0) {
                                visited[I][J][newStatus] = 1;
                                q.push({I, J, steps + 1, newStatus});
                            }
                        }
                        else {
                            if (visited[I][J][status] == 0) {
                                visited[I][J][status] = 1;
                                q.push({I, J, steps + 1, status});
                            }
                        }
                    }
                }
            }
    
            return -1; 
        }
    };
    


