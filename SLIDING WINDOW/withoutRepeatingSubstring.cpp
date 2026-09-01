#include <bits/stdc++.h>
using namespace std;

// LC 3 
// Sliding Window 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 1) return 1;
        unordered_map<char, int> mp;
        int maxLen = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};