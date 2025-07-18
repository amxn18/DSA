#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // Edge case: if needle is empty, return 0
        if (m == 0) return 0;

        // Loop through haystack until remaining length is less than needle
        for (int i = 0; i <= n - m; i++) {
            // Check if substring from i matches needle
            if (haystack.substr(i, m) == needle) {
                return i;  // Found the first occurrence
            }
        }

        // If no match found, return -1
        return -1;
    }
};