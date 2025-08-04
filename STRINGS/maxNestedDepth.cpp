#include <bits/stdc++.h>
using namespace std;
// Method 1 Using Stack
// LC 1616
// TC O(n)
// SC O(n)
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;
        int maxDepth = 0;
        for(auto ch : s){
            if(ch == '('){
                st.push(ch);
                if(st.size() > maxDepth) maxDepth = st.size();
            }
            else if(ch == ')')st.pop();
        }
        return maxDepth;
    }
};

// Method 2 Using Counter
// LC 1616
// TC O(n)
// SC O(1)

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int depth = 0;
        for(char ch : s){
            if(ch == '('){
                depth++;
                if(depth > maxDepth) maxDepth = depth;
            }
            else if(ch == ')') depth--;
        }
        return maxDepth;
    }
};