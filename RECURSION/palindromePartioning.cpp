#include <bits/stdc++.h>
using namespace std;

// LC 131: Palindrome Partitioning
// TC O(N * 2^N), SC O(N)
class Solution {
public:
    vector<vector<string>> result;
    void f(int idx, string& s, vector<string>& temp){
        if(idx == s.size()){
            result.push_back(temp);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                f(i+1, s, temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        f(0, s, temp);
        return result;
    }
};