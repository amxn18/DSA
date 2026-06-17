#include <bits/stdc++.h>
using namespace std;

// LC 733. Flood Fill
class Solution {
public:
    vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        if(image[sr][sc] == color) return image; //* 
        int originalColor = image[sr][sc];
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int i = u.first;
            int j = u.second;
            for(auto dir: dirs){
                int newI = i + dir[0];
                int newJ = j + dir[1];
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && image[newI][newJ] == originalColor){
                    image[newI][newJ] = color;
                    q.push({newI, newJ});
                }
            }
        }
        return image;
    }
};