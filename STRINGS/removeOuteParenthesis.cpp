#include <bits/stdc++.h>
using namespace std;

// Method 1 Using Temporary String
// TC O(n)
// SC O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp = "";
        string result = "";
        int count = 0;
        for(char ch : s){
            temp += ch;
            if(ch == '(') count++;
            else count--;

            if(count == 0){   // Valid Group Found
               result += temp.substr(1, temp.size()-2);  // -2 because of one this "("  and one this ")"
               temp = "";// reset;
        }
        }
        return result;
    }
};

// Method 2 Using Stack
// TC O(n)
// SC O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result = "";
        for(char ch : s){
            if(ch == '('){
                if(!st.empty()) result += ch;
                st.push(ch);
            }
            else{   // ch == ")"
                st.pop();   //remove "("
                if(!st.empty()) result += ch;
            }
        }
        return result;
    }
};



// Optimal solution to remove outer parentheses from a valid parentheses string
// LC 1021
// TC O(n)
// SC O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        for(char ch : s){
            if(ch == '('){
                if(depth > 0) result += ch;
                depth++;
            }else{
                depth--;
                if(depth > 0) result += ch;
            }
        }
        return result;
    }
};