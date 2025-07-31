#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1)
                return num.substr(0, i + 1);
        }
        return "";
    }
};

// LC 1903
// TC O(n) - We traverse the string once to find the last odd digit.
// SC O(1) - We use a constant amount of space for variables.

