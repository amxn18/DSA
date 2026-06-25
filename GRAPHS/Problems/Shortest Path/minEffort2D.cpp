#include <bits/stdc++.h>
using namespace std;

// LC 1631
class Solution {
public:
    vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    typedef pair<int, pair<int,int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0,0}});

        while (!pq.empty()) {
            int diff = pq.top().first;
            auto cord = pq.top().second;
            int i = cord.first;
            int j = cord.second;
            pq.pop();

            if (diff > result[i][j]) continue;

            for (auto &dir : dirs) {
                int I = i + dir[0];
                int J = j + dir[1];

                if (I >= 0 && I < m && J >= 0 && J < n) {
                    int absDiff = abs(heights[i][j] - heights[I][J]);
                    int maxDiff = max(diff, absDiff);

                    if (result[I][J] > maxDiff) {
                        result[I][J] = maxDiff;
                        pq.push({maxDiff, {I, J}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
