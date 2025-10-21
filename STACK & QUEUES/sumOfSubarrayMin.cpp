#include <bits/stdc++.h>
using namespace std;

// Method 1 (Brute)
// TC O(n^2) SC O(1)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 10e+7;
        int sum = 0;
        for(int i =0; i<arr.size(); i++){
            int mini = arr[i];
            for(int j = i; j<arr.size(); j++){
                mini = min(mini, arr[j]);
                sum = (sum+mini)%mod;
            }
        }   
        return sum;
    }
};

// Method 2 (Optimal)
// TC O(n) SC O(n)

class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long finalSum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            long long count = (left * right) % mod;
            finalSum = (finalSum + (arr[i] * count) % mod) % mod;
        }

        return finalSum;
    }
};
