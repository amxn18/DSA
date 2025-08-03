#include <bits/stdc++.h>
using namespace std;
// Method 1
// LC 796
// TC O(n^2)
// SC O(n)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i=0; i<n; i++){
            string rotated = s.substr(i) + s.substr(0, i);
            if(rotated == goal) return true;
        }
        return false;
    }
};

// Method 2
// TC O(n^2)
// SC O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i=0; i<n; i++){
            char first = s[0];
            s.erase(s.begin());
            s.push_back(first);

            if(s == goal) return true;
        }
        return false;
    }
};

// Method 3
// TC O(n)  
// SC O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }
};