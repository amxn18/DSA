#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string& s, int i, long long num) {
        if (i >= s.size() || !isdigit(s[i])) return num;
        
        int digit = s[i] - '0';
        if (num > (INT_MAX - digit) / 10) {
            return (long long)INT_MAX + 1;
        }
        return solve(s, i + 1, num * 10 + digit);
    }
    
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while (i < n && s[i] == ' ') i++;
        if (i >= n) return 0;
        int sign = 1;
        if (i < n && s[i] == '+') {
            i++;
        }
        else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        long long result = solve(s, i, 0);
        long long finalResult = sign * result;
        if (finalResult > INT_MAX) return INT_MAX;
        if (finalResult < INT_MIN) return INT_MIN;
        
        return (int)finalResult;
    }
};

// TC = O(n)
// SC = O(n) (recursion stack space)