#include <bits/stdc++.h>
using namespace std;

// LC 139. Word Break
// Brute Force Recursion

// bool Solve(string& s, int idx, vector<string>& temp, vector<string>& wordDict){
//     if(idx == s.size()) return true;
//     if(wordDict.find(s)) return true;
//     for(int i=1; i<s.size(), i++){
//         temp.push_back(s.substr(idx, i));
//         if(wordDict.find(temp) && Solve(s, idx+i, temp, wordDict)) return true;
//         temp.pop_back();
//     }
//     return false;

// }

// Method 1 Rec+Memoization

class Solution {
public:
    unordered_set<string> st;
    int t[301];
    bool solve(int idx, string& s) {
        int n = s.size();
        if (idx == n) return true;

        if(t[idx] != -1) return t[idx];
        for (int len = 1; len <= n - idx; len++) {  
            string temp = s.substr(idx, len);
            if (st.find(temp) != st.end()) {
                if (solve(idx + len, s))  
                    return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            st.insert(word);
        }
        memset(t, -1, sizeof(t));
        return solve(0, s);
    }
};

// TC O(n^2)
// SC O(n) + O(n) for recursion stack
