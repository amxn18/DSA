#include <bits/stdc++.h>
using namespace std;

// LC 22: Generate Parentheses
// TC: O(4^n/sqrt(n)), SC: O(n)
class Solution {
public:
    void generate(int n, string curr, int open, int close, vector<string>& result){
        if(curr.size() == 2*n){
            result.push_back(curr);
            return;
        }
        if(open < n){
            generate(n, curr+"(", open+1, close, result);
        }
        if(close < open){
            generate(n, curr+")", open, close+1, result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, "", 0, 0, result);
        return result;
    }
};