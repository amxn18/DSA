#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;
        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j<n; j++){
                freq[s[j] - 'a']++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for(auto f : freq){
                    if(f>0){
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }
                total += (maxFreq-minFreq);
            }
        }
        return total;
    }
};

// LC 1769
// TC O(n^2 * 26) => O(n^2)
// SC O(1) since freq array size is constant (26)