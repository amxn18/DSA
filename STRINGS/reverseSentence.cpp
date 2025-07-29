#include <bits/stdc++.h>
using namespace std;

// Method 1 (Brute) Using Stack
// LC 151
// TC O(2n)
// SC O(n)
class Solution {
public:
    string reverseWords(string s) {
        int n =  s.size();
        stack<string> st;
        string word = "";
        string result = "";
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                word += s[i];   // build the word
            } else if(!word.empty()){  // Word Completed
                st.push(word);
                word = "";
            }
        }
        if(!word.empty()) st.push(word);  // Push Last Word
        while(!st.empty()){
            result += st.top();
            st.pop();
            if(!st.empty()) result += " ";
        }
        return result;
    }
};

// Optimal Solution (Without Stack)

// TC O(3n) --> O(n) for trimming spaces, O(n) for reversing the whole string, and O(n) for reversing each word
// SC O(1) (Ignoring the output string)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;
        while(l<=r && s[l] == ' ')l++;
        while(r>=l && s[r] == ' ')r--;  // Trim Down The Extra spaces

        string result = "";
        string word = "";
        while(l<=r){
            if(s[l] != ' ') word += s[l];
            else if(!word.empty()){
                result += word + ' ';
                word = "";
            }
            l++;
        }
        if(!word.empty()) result += word;  // last word

        reverse(result.begin(), result.end());

        int start = 0;
        for(int i=0; i<=result.length(); i++){
            if(i == result.length() || result[i] == ' '){
                reverse(result.begin()+start, result.begin()+i);
                start = i+1;
            }
        }
        return result;
    }
};