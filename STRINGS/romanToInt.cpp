#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int total = 0;
        int prev = 0;
        for(int i=n-1; i>=0; i--){
            int curr = roman[s[i]];
            if(curr < prev) total -= curr;
            else total += curr;
            prev = curr;
        }
        return total;
    }
};

// LC 13
// TC O(n) 
// SC O(1) 
