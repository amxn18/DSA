#include <bits/stdc++.h>
using namespace std;

// LC 455 TC O(nlogn+mlogm) SC O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; 
        int j = 0;

        while(i < m && j < n){
            if(g[i] <= s[j]) i++;
            j++;
        }

        return i;
    }
};