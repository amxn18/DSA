#include <bits/stdc++.h>
using namespace std;
// LC 542. 01 Matrix
// TC O(m*n) SC O(m*n)
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<P> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            P curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            for(auto dir : dirs){
                int newI = i + dir[0];
                int newJ = j + dir[1];
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && res[newI][newJ] == -1) {
                    res[newI][newJ] = res[i][j] + 1;
                    q.push({newI, newJ});
                }
            }
        }
        return res;
    }
};