#include <bits/stdc++.h>
using namespace std;

// LC 85
// TC O(n*m) + O(n*2m)
// SC O(n*m) + O(n)
class Solution {
public: 
    int areaHistogram(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, arr[el] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int el = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, arr[el] * (nse - pse - 1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(matrix[i][j] == '0') sum = 0;
                else sum += 1;
                prefixSum[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, areaHistogram(prefixSum[i]));
        }
        return maxArea;
    }
};
