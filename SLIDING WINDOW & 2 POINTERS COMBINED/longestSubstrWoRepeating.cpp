#include <bits/stdc++.h>
using namespace std;

// LC 3 
// Method 1: Brute Force TC ~ O(N^2)  | SC ~ O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int hash[256] = {0};
            for(int j=i; j<n; j++){
                if(hash[s[j]] == 1) break;
                int len = j-i+1;
                maxLen = max(len, maxLen);
                hash[s[j]] = 1;
            }
        }
        return maxLen;
    }
};

// Method 2: Sliding Window + 2 Pointers TC ~ O(N) | SC ~ O(256)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> hash(256, -1); 
        int l = 0, maxLen = 0;

        for (int r = 0; r < n; r++) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l)
                l = hash[s[r]] + 1;

            hash[s[r]] = r; 
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
