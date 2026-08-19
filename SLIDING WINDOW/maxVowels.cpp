#include <bits/stdc++.h>
using namespace std;

// LC 1456. Maximum Number of Vowels in a Substring of Given Length
class Solution {
public:
    bool isVowel(char& ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxVowels = 0;
        int count = 0;
        while(j<n){
            if(isVowel(s[j])) count++;
            if(j-i+1 == k){
                maxVowels = max(maxVowels, count);
                if(isVowel(s[i])) count--;
                i++;
            }
            j++;
        }
        return maxVowels;
    }
};