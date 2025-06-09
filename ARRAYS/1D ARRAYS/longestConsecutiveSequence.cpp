#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i =0; i<n; i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int ctr = 1;;
            int x = it;
            while(st.find(x+1) != st.end()){
                ctr++;
                x++;
            }
            longest = max(longest, ctr);
        }
    }
    return longest;
}

// TC --> O(2n)
// SC --> O(n)