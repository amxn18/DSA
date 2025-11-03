#include <bits/stdc++.h>
using namespace std;


// Method 1: Brute Force TC O(n^2) SC(256)
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                if(mp.size() > k) break;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

// Method 2: Sliding Window + 2 Pointers TC O(n) SC(256)
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int maxLen = 0;
        unordered_map<char, int> mp;
        int l = 0;
        for(int r=0; r<s.size(); r++){
            mp[s[r]]++;
            if(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
            }
            l++;
            if(mp.size() < k) maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};