// LC 1326 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minTaps(int n, vector<int>& ranges) {
            int x = ranges.size();
            vector<int> startEnd(n+1);
            for(int i=0; i<x; i++){
                int start = max(0, i-ranges[i]);
                int end = min(n, i+ranges[i]);
    
                startEnd[start] = max(startEnd[start], end);
            }
            int taps = 0;
            int maxEnd = 0;
            int currEnd = 0;
    
            for(int i=0; i<=n; i++){
                if(i>maxEnd) return -1;
                if(i > currEnd){
                    taps++;
                    currEnd = maxEnd;
                }
                maxEnd = max(maxEnd, startEnd[i]);
            }
            return taps;
        }
    };
/*
        Explanation:
        - We treat each tap as an interval [i - ranges[i], i + ranges[i]].
        - Convert this into an array where startEnd[i] stores the farthest position 
          that can be watered from index 'i'.
        - Then, use a greedy approach similar to "Jump Game II":
          1. Try to extend the max reachable end (maxEnd).
          2. If we reach a point beyond our maxEnd, return -1 (not possible).
          3. Whenever we exceed our current coverage (currEnd), we increment taps 
             and update currEnd to maxEnd.
        - This ensures the minimum number of taps are used while covering the garden.

        Time Complexity: O(N), as we iterate through the garden at most twice.
        Space Complexity: O(N), for storing the startEnd array.
        */