#include <bits/stdc++.h>
using namespace std;

// LC 509: Fibonacci Number
// Method 1: Recursion TC O(2^n) SC O(n) due to recursion stack
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};

// Method 2: Recursion + Memoization (Top-Down DP) TC O(n) SC O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// Method 3: Tabulation (Bottom-Up DP) TC O(n) SC O(n)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Method 4: Space Optimization TC O(n) SC O(1)
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int a = 0;
        int b = 1;
        int c;
        for(int i=1; i<n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
