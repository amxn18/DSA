#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0; 

        int mod = 100000;
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;

        dist[start] = 0;
        q.push({start, 0});

        while (!q.empty()) {
            int u = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto v : arr) {
                int num = (u * v) % mod;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};

// TC --> O(N*M) N = 100000 M = arr.size()  SC --> O(N)