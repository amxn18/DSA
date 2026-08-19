#include <bits/stdc++.h>
using namespace std;

// LC 76. Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n) return "";
        unordered_map<char, int> mp;
        for(auto ch: t) mp[ch]++;
        int minLen = INT_MAX;
        int reqCount = m;
        int i = 0;
        int j = 0;
        int start_i = 0;
        while(j<n){
            char ch = s[j];
            if(mp[ch] > 0) reqCount--;
            mp[ch]--;
            while(reqCount == 0){
                int currLen = j-i+1;
                if(minLen > currLen){
                    minLen = currLen;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) reqCount++;
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(start_i, minLen);
    }
};