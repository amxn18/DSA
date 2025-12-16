#include <bits/stdc++.h>
using namespace std;

// LC 733. Flood Fill
// TC O(m*n) SC O(m*n)
// DFS Approach
class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {1,0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<int>>& ans, vector<vector<int>>& img, int iColor, int newColor){
        ans[i][j] = newColor;
        int n = img.size();
        int m = img[0].size();
        for(auto dir : dirs){
            int nI = i + dir[0];
            int nJ = j + dir[1];
            if(nI >=0 && nI < n && nJ >=0 && nJ < m && ans[nI][nJ] == iColor && ans[nI][nJ] != newColor) dfs(nI, nJ, ans, img, iColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, initialColor, color);
        return ans;
    }
};

// BFS Approach
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<P> q;
        int initialColor = image[sr][sc];
        if(initialColor == color) return image;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            P curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            for(auto dir : dirs){
                int newI = i + dir[0];
                int newJ = j + dir[1];
                if(newI >= 0 && newI < m && newJ >=0 && newJ < n && image[newI][newJ] == initialColor && image[newI][newJ] != color){
                    image[newI][newJ] = color;
                    q.push({newI, newJ});
                }
            }
        }
        return image;
    }
};