#include <bits/stdc++.h>
using namespace std;

// LC 451
// Method 1 
// TC O(n + klogk)  k is the number of unique characters
// SC O(k)

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for(auto ch : s){
            freq[ch]++;
        }
        vector<pair<char, int>> charFreq(freq.begin(), freq. end());
        sort(charFreq.begin(), charFreq.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string result = "";
        for(auto &[ch, count] : charFreq){
            result += string(count, ch);   // append ch count times;
        }
        return result;
    }
};

// Method 2 (Bucket Sort)
// TC O(n)
// SC O(n)

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for(auto ch : s){
            freq[ch]++;
        }
        vector<vector<char>> bucketList(n+1);
        for(auto it : freq){
            char ch = it.first;
            int count = it.second;
            bucketList[count].push_back(ch);
        }
        string result = "";
        for(int i = n; i>=1; i--){
            for(char ch : bucketList[i]){
                result += string(i, ch);
            }
        }
        return result;
    }
};

