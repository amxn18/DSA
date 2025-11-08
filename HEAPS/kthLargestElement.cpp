#include <bits/stdc++.h>
using namespace std;

// LC 215
// TC -- O(N log K)
// SC -- O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x: nums){
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};