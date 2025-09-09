#include <bits/stdc++.h>
using namespace std;

// LC 282
// TC O(3^(n-1) * n)  where n is length of num
// SC O(n) for recursion stack + O(k) for ans array where k is no of valid expressions
class Solution {
public:
    vector<string> ans;
    void backtrack(string& num, int target, int idx, long currVal, long lastNum, string path){
        if(idx == num.size()){
            if(currVal == target) ans.push_back(path);
            return;
        }
        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[idx] == '0') break;   
            string currStr = num.substr(idx, i - idx + 1);
            long currNum = stol(currStr);
            if(idx == 0){
                backtrack(num, target, i+1, currNum, currNum, currStr);
            } else {
                backtrack(num, target, i+1, currVal + currNum, currNum, path + "+" + currStr);
                backtrack(num, target, i+1, currVal - currNum, -currNum, path + "-" + currStr);
                backtrack(num, target, i+1, currVal - lastNum + lastNum*currNum, lastNum*currNum, path + "*" + currStr);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return ans;
    }
};
