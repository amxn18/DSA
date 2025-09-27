#include <bits/stdc++.h>
using namespace std;

// For single array
vector<int> nge1(vector<int>& arr){
    stack<int> st;
    vector<int> ans;
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i])st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

// LC 496
// TC O(n+m) 
// SC O(n) 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i = nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int x : nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};

