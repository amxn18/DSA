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

//     Initialize candies:

// Each child gets at least 1 candy, so we start with candy = n.

// Iterate through ratings:

// If ratings are equal, move to the next index (no extra candies needed).

// Handle Increasing Slope (Peak Formation):

// If ratings[i] > ratings[i-1], increase the peak counter and add peak candies.

// Continue until the peak is reached.

// Handle Decreasing Slope (Dip Formation):

// If ratings[i] < ratings[i-1], increase the dip counter and add dip candies.

// Continue until the dip ends.

// Adjust Overcounting:

// The peak was counted twice (once in increasing and once in decreasing slope).

// Subtract min(peak, dip) to fix the double count.

// Return total candies.