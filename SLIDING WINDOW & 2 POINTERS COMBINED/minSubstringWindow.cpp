#include <bits/stdc++.h>
using namespace std;

// LC 76
// TC O(2n) + O(m) SC O(1)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return ""; 

        vector<int> freqT(256, 0), freqS(256, 0);
        for (char c : t) freqT[c]++; 

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int startIdx = 0;
        int count = 0;  
        while (r < n) {
            char c = s[r];
            freqS[c]++;
            if (freqT[c] != 0 && freqS[c] <= freqT[c])
                count++;

            while (count == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                char leftChar = s[l];
                freqS[leftChar]--;

                if (freqT[leftChar] != 0 && freqS[leftChar] < freqT[leftChar])
                    count--;

                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
