#include <bits/stdc++.h>
using namespace std;

// LC 402: Remove K Digits
// TC : O(2n), SC: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            if (!st.empty() || num[i] != '0') {
                st.push(num[i]);
            }
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};
