#include <bits/stdc++.h>
using namespace std;

// LC 904 
// Method 1: Brute Force --> TC ~O(N^2) SC ~O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                st.insert(fruits[j]);
                if(st.size() <=2) maxLen = max(maxLen, j-i+1);
                else break;
            }
        }
        return maxLen;
    }
};

// Method 2 : Sliding Window + HashMap --> TC ~O(N) SC ~O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int l = 0;
        int maxLen = 0;
        for(int r=0; r<n; r++){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size() <= 2) maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};