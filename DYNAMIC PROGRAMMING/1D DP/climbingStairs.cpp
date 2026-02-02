#include <bits/stdc++.h>
using namespace std;

// LC 70: Climbing Stairs
// Method 1 (Recursion) TC O(2^n) SC O(n):
class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Method 2 (Memoization) TC O(n) SC O(n):
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n<0) return 0;
        if(t[n] != -1) return t[n];
        if(n == 0) return 1;
        return t[n] = solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};

// Method 3 (Tabulation) TC O(n) SC O(n):
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2 || n==3) return n;
        vector<int> t(n+1, -1);
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
        for(int i=3; i<=n; i++){
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
};

// Method 4 (Space Optimization) TC O(n) SC O(1):
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        int a = 1;
        int b = 2;
        int c = 3;
        for(int i=3; i<=n; i++){
            c = b+a;
            a = b;
            b = c;
        }
        return c;
    }
};