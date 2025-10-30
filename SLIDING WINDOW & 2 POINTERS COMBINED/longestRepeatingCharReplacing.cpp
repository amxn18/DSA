#include <bits/stdc++.h>
using namespace std;

// LC 424
// Method 1: Brute Force --> TC ~O(N^2) SC ~O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int maxFreq = 0;
            vector<int> hash(26, 0);
            for(int j=i; j<n; j++){
                hash[s[j]-'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                int windowLen = j-i+1;
                int changesPossible = windowLen - maxFreq;

                if(changesPossible <=k) maxLen = max(maxLen, windowLen);
            }
        }
        return maxLen;
    }
};

// Method 2 : Sliding Window + HashMap --> TC ~O(N) SC ~O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);
        int maxFreq = 0;
        while(r < s.size()){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            while((r-l+1) - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            } 
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};