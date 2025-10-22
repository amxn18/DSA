#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// TC : O(5n) = O(n), SC: O(4n)

class Solution {
public: 
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = getNSL(heights, n);
        vector<int> NSR = getNSR(heights, n);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};

// Optimized Approach
// TC : O(2n), SC: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (heights[el] * (nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (heights[el] * (nse-pse-1)));
        }
        return maxArea;
    }
};