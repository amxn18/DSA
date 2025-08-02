#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool BS(vector<string>& strs, int len){
        string prefix =strs[0].substr(0, len);
        for(int i=1; i<strs.size(); i++){
            if(strs[i].substr(0, len) != prefix) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minLen = INT_MAX;
        for(auto str : strs){
            minLen = min(minLen, (int)str.size());
        }
        int low = 0;
        int high = minLen;
        while(low <= high){
            int mid = (low + high)/2;
            if(BS(strs, mid)) low = mid+1;
            else high = mid-1;
        }
        return strs[0].substr(0, (low+high)/2);
    }
};

// LC 14
// TC O(n*log(m)) - We perform binary search on the length of the prefix, and for each length, we check all strings.
// SC O(1) - We use a constant amount of space for variables.