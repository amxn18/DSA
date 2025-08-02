#include <bits/stdc++.h>
using namespace std;
// LC 205
// Method 1 
// TC O(n)
// SC O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> mp;
        unordered_set<char> mapped;
        for(int i=0; i<s.size(); i++){
            char a = s[i];
            char b = t[i];

            if(mp.count(a)){
                if(mp[a] != b) return false;
            } 
            else{
                if(mapped.count(b))return false;
                mp[a] = b;
                mapped.insert(b);
            }
        }
        return true;
    }
};

// Method 2

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> st, ts;
        for(int i=0; i<s.size(); i++){
            char a = s[i];
            char b = t[i];

            if(st.count(a) && st[a] != b) return false;
            if(ts.count(b) && ts[b] != a) return false;

            st[a] = b;
            ts[b] = a;
        }
        return  true;
    }
};