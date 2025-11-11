#include <bits/stdc++.h>
using namespace std;

//TC --> O(nlogK)  SC --> O(k)
class Solution {
  public:
    vector<int> KSortedArray(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> result;
        for(int i=0 ; i<=k; i++){
            pq.push(arr[i]);
        }
        for(int i=k+1; i<n; i++){
            result.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
        
    }
};