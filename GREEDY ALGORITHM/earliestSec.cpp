#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        int m, n;
        bool allIdxMarked(int sec, vector<int>& changeIndices, vector<int>& nums){
            vector<int> lastPosi(n+1, -1);
            for(int i=0; i<=sec; i++){
                int idx = changeIndices[i];
                lastPosi[idx] = i+1; //Timing is 1 based
            }
            for(int i=1; i<=n; i++){
                if(lastPosi[i] == -1) return false; //i was not there in range till seconds
            }
            map<int,int> posiIndex; //orderedmap --> sorted order of last appearance
            for(int i=1; i<=n; i++){
                int posi = lastPosi[i];
                posiIndex[posi] = i;
            }
    
            int timePassed = 0;
            for(auto& [position, index] : posiIndex){
                int req_time = nums[index-1] + 1; //decrement till 0 + 1 to mark it
                if(req_time + timePassed > position) return false;
                timePassed += req_time;
            }
            return true;
        }
        int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
            m = changeIndices.size();
            n = nums.size();
            for(int time=0; time<m; time++){
                if(allIdxMarked(time, changeIndices, nums)) return time+1;
            }
            return -1;
        }
    };


    // # Leetcode 3048: Earliest Second to Mark Indices
    // # Approach:
    // # 1. Iterate over the time (seconds) and check if all indices can be marked within that time.
    // # 2. Maintain an array to track the last time each index appeared in 'changeIndices'.
    // # 3. Use an ordered map to store the indices sorted by their last appearance time.
    // # 4. Simulate marking indices in increasing order of their last appearance while ensuring
    // #    there is enough time to complete the marking.
    // # 5. Use binary search or linear search to find the earliest second that allows marking all indices.
    
    // # Time Complexity: O(m * n) (Worst case: checking all seconds)
    // # Space Complexity: O(n) (Tracking positions and indices)
    