#include <bits/stdc++.h>
using namespace std;
//  LC 1642 
class Solution {
    public:
        int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
            int n = heights.size();
            priority_queue<int> pq;
            int i = 0;
            // only before last building i--> i+1
            for(; i<n-1; i++){
                if(heights[i+1] <= heights[i]) continue;
                int diff = heights[i+1] - heights[i];
                if(bricks >= diff){
                    bricks -= diff;
                    pq.push(diff);
                } else if(ladders > 0) {
                    if(!pq.empty()){
                        int maxPastUsed = pq.top();
                        if(diff < maxPastUsed){
                            bricks += maxPastUsed;
                            pq.pop();
                            bricks -= diff;
                            pq.push(diff);
                        } 
                    }
                    ladders --;
    
                } else break;
            }
            return i;
        }
    };

//     # Leetcode 1642: Furthest Building You Can Reach
// # Approach (Lazy Greedy using Max Heap):
// # - Traverse buildings from left to right.
// # - If the next building is taller, calculate the height difference.
// # - If possible, use bricks first and store the used amount in a max heap.
// # - If bricks are insufficient but ladders are available:
// #     - Replace the largest previously used brick cost with a ladder if beneficial.
// # - If neither bricks nor ladders can be used, stop.
// # - Return the last reachable building index.

// # Time Complexity: O(n log n)  (log n for each priority queue operation)
// # Space Complexity: O(n)  (for priority queue storage)
