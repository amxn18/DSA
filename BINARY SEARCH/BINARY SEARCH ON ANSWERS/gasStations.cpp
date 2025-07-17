#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// TC: O(n*k + n)
// SC: O(n)
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n-1, 0); //n-1 len filled with zeros
        for(int g = 1; g<=k; g++){
            long long maxSec = -1;
            int maxIdx = -1;
            for(int i=0; i<n; i++){
                long double diff = stations[i+1] - stations[i];
                long long secLen = diff/(howMany[i]+1);
                if(maxSec < secLen){
                    maxSec = secLen;
                    maxIdx = i;
                }
            }
            howMany[maxIdx]++;
        }
        long double maxAns = -1;
        for(int i=0; i<n; i++){
            long double secLen = (stations[i+1] - stations[i])/(howMany[i]+1);
            maxAns = max(maxAns, secLen);
        }
        return maxAns;
        
    }
};


// Method 2 Using Priority Queue
// TC: O(n log n + k log n) where n is the number of stations
// SC: O(n)
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n-1, 0);
        priority_queue<pair<long double, int>> pq;
        for(int i=0; i<n-1; i++){  // 4 gas stations so 3 gaps
            pq.push({stations[i+1]-stations[i], i});
        }
        for(int g=1; g<=k; g++){
            auto tp = pq.top();
            pq.pop();
            int secIdx = tp.second;
            howMany[secIdx]++;
            long double inDiff = stations[secIdx+1] - stations[secIdx];
            long double secLen = inDiff/(howMany[secIdx]+1);
            pq.push({secLen, secIdx});
        }
        return pq.top().first;
    }
};

// Method 3 Using Binary Search
class Solution {
  public:
    int countofstations(vector<int> &stations, long double dist){
        int n = stations.size();
        int ctr = 0;
        for(int i=0; i<n; i++){
            int inbw = (stations[i+1] - stations[i]/ dist);
            if((stations[i]-stations[i-1]/dist) == inbw+dist){
                inbw--;
            }
            ctr += inbw;
        }
        return ctr;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        long double low = 0;
        long double high = 0;
        for(int i=0; i<n-1; i++){
            high = max(high, (long double)(stations[i+1]-stations[i]));
        }
        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = (high+low)/2.0;
            int cnt = countofstations(stations, mid);
            if(cnt > k){
                low = mid;
            } else high = mid;
            
        }
        return high;
    }
};