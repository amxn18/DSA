#include <bits/stdc++.h>
using namespace std;

// LC 994. Rotting Oranges
// TC O(2*(m*n)) SC O(m*n)
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> dirs{{-1,0}, {1,0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<P> q;
        int freshCount = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) freshCount++;
            }
        }
        if(freshCount == 0) return 0; // Already all are rotten
        int minutes = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                P curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(auto dir : dirs){
                    int newI = i + dir[0];
                    int newJ = j + dir[1];
                    if(newI >= 0 && newI < m && newJ >=0 && newJ < n && grid[newI][newJ] == 1){
                        grid[newI][newJ] = 2;
                        q.push({newI, newJ}); // Push So that it can rot its neighbour next
                        freshCount--;
                    }
                }
            }
            minutes++;
        } 
        return freshCount == 0 ? minutes-1 : -1; 
    }
};