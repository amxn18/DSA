#include <bits/stdc++.h>
using namespace std;

// LC 2104
class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n, bool isMax) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && 
                   (isMax ? arr[st.top()] <= arr[i] : arr[st.top()] > arr[i])) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int>& arr, int n, bool isMax) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && 
                   (isMax ? arr[st.top()] < arr[i] : arr[st.top()] >= arr[i])) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSLmax = getNSL(arr, n, true);
        vector<int> NSRmax = getNSR(arr, n, true);

        vector<int> NSLmin = getNSL(arr, n, false);
        vector<int> NSRmin = getNSR(arr, n, false);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long leftMax = i - NSLmax[i];
            long long rightMax = NSRmax[i] - i;
            long long leftMin = i - NSLmin[i];
            long long rightMin = NSRmin[i] - i;

            long long totalMax = leftMax * rightMax;
            long long totalMin = leftMin * rightMin;

            total += (1LL * arr[i] * (totalMax - totalMin));
        }

        return total;
    }
};
