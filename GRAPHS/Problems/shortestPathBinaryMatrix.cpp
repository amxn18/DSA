#include <bits/stdc++.h>
using namespace std;

// LC 1091
// USING BFS --> TC (m*n), SC (m*n)
class Solution {
public:
    vector<vector<int>> dirs{{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int d = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i == m-1 && j == n-1) return d+1;
                for(auto dir : dirs){
                    int I = i + dir[0];
                    int J = j + dir[1];
                    if(I >=0 && I<m && J>= 0 && J<n && grid[I][J] != 1){
                        q.push({I, J});
                        grid[I][J] = 1;
                    }
                }
            }
            d++;
        }
        return -1;
    }
};

// USING DIJIKSTRA  TC O(m*n log(m*n))
// 1) TLE 
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs{{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, {0,0}});
        result[0][0] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            auto cord = pq.top().second;
            int i = cord.first;
            int j = cord.second;
            pq.pop();
            for(auto dir : dirs){
                int newI = i + dir[0];
                int newJ = j + dir[1];
                int dist = 1;
                if(newI >=0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 0 && d + dist <= result[newI][newJ]){
                    pq.push({d+dist, {newI, newJ}});
                    result[newI][newJ] = d+dist;
                }
            }
        }
        if(result[m-1][n-1] == INT_MAX) return -1;
        return result[m-1][n-1] + 1;
    }
};

// 2) 
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({1, {0,0}});
        result[0][0] = 1;

        while (!pq.empty()) {
            int d  = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();

            int i = cord.first;
            int j = cord.second;

            if (d > result[i][j]) continue;
            if (i == m-1 && j == n-1) return d;

            for (auto &dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==0) {
                    if (d + 1 < result[ni][nj]) {
                        result[ni][nj] = d + 1;
                        pq.push({d + 1, {ni, nj}});
                    }
                }
            }
        }
        return -1;
    }
};
