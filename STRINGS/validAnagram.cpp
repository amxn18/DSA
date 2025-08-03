#include <bits/stdc++.h>
using namespace std;

// Method 1
// LC 242
// TC O(2*nlogn)
// SC O(1) if in place sort is used
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Method 2 
// TC O(n)
// SC O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        int count[26] = {0};
        for(int i=0; i<n; i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
};
