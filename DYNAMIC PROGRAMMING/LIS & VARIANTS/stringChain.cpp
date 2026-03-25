#include <bits/stdc++.h>
using namespace std;

// LC 1048 - Longest String Chain
class Solution {
public: 
    int n;
    int dp[1001][1001]; 

    bool isPred(string& prev, string& curr) {
        int a = prev.length();
        int b = curr.length();
        if (a >= b || b - a != 1) return false;
        int i = 0, j = 0;
        while (i < a && j < b) {
            if (prev[i] == curr[j]) i++;
            j++;
        }
        return i == a;
    }

    int solve(int idx, int prev, vector<string>& words) {
        if (idx >= n) return 0;
        if (prev != -1 && dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int taken = 0, leave = 0;
        if (prev == -1 || isPred(words[prev], words[idx])) {
            taken = 1 + solve(idx + 1, idx, words);
        }
        leave = solve(idx + 1, prev, words);

        if (prev != -1) {
            return dp[idx][prev + 1] = max(taken, leave);
        }
        return max(taken, leave);
    }

    static bool lambda(string& w1, string& w2) {
        return w1.length() < w2.length();
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), lambda);
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, words);
    }
};

// Bottom-Up Tabulation  TC O(N^2)  SC O(N^2)
class Solution {
public:
    int n;
    bool isPred(string& prev, string& curr) {
            int a = prev.length();
            int b = curr.length();
            if (a >= b || b - a != 1) {  
                return false;
            }
            int i = 0, j = 0;
            while (i < a && j < b) {
                if (prev[i] == curr[j]) i++;
                j++; 
            }
            return i == a; 
        }
    static bool lambda(string& w1, string& w2) {
            return w1.length() < w2.length();
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), lambda);

        vector<int> dp(n, 1);
        int maxL = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPred(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxL = max(maxL, dp[i]);
                }
            }
        }
        return maxL;
    }
};