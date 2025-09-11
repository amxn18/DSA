#include <bits/stdc++.h>
using namespace std;

// LC 2220. Minimum Bit Flips to Convert Number
// TC O(1), SC O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ctr = 0;
        int ans = start^goal;
        for(int i=0; i<31; i++){
            if(ans&(1<<i))ctr++;
        }
        return ctr;
    }
};