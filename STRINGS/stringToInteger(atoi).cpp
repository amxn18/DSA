#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long num = 0;
        while(i < n && s[i] == ' ') i++;
        if(i < n && s[i] == '+') {
            sign = 1;
            i++;
        } 
        else if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        while(i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if(num * sign > INT_MAX) return INT_MAX;
            if(num * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return num * sign;
    }
};

// LC 8
// TC O(n)
// SC O(1)
