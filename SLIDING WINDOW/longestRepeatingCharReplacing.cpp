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

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int i = 0;
        int j = 0;

        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxLen = 0;
        while(j<n){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq, freq[s[j] -'A']);
            
            while((j-i+1) - maxFreq > k){
                freq[s[i]-'A']--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};