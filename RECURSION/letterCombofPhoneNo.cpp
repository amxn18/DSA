#include <bits/stdc++.h>
using namespace std;

// LC 17. Letter Combinations of a Phone Number
// TC --> O(4^n * n) SC --> O(n) + O(4^n * n)
// where 4^n is the maximum number of combinations when each digit maps to 4
// and n is the average length of each combination

class Solution {
public:
    vector<string> result;
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void f(int idx, string& digits, string& temp){
        if(idx == digits.size()){
            if(!temp.empty()){
                result.push_back(temp);
            }
            return;
        }
        int digit = digits[idx] - '0';
        for(char c : mapping[digit]){
            temp.push_back(c);
            f(idx+1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string temp;
        f(0, digits, temp);
        return result;  
    }
};

// M2
class Solution {
public:
    vector<string> result;
    void solve(int idx, string& digits, string& temp, unordered_map<char, string>& mp){
        if(idx >= digits.length()){
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0; i<str.length(); i++){
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        solve(0, digits, temp, mp);
        return result;
    }
};