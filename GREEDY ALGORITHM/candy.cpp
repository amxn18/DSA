#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            // Each person 1 candy
            int candy = n;
            int i=1;
            while(i<n){
                if(ratings[i] == ratings[i-1]){
                    i++;
                    continue;
                }
                // Increasing Slope --> Peak
                int peak = 0;
                while(ratings[i] > ratings[i-1]){
                    peak++;
                    candy += peak;
                    i++;
                    if(i==n) return candy;
                }
                // Decreasing Slope --> Dip
                int dip = 0;
                while(i< n && ratings[i] < ratings[i-1]){
                    dip++;
                    candy += dip;
                    i++;
                }
    
                // At top peak both peak and dip was added so
                candy -= min(peak,dip);
            }
            return candy;
        }
    };

