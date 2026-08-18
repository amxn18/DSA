#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool allFreqZero(vector<int>& freq){
        for(auto it: freq){
            if(it != 0) return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
        int n = txt.size();
        int k = pat.size();
        vector<int> freq(26, 0);
        // S1) Create Frequency record of characters in pat
        for(int i=0; i<k; i++){
            char ch = pat[i];
            freq[ch-'a']++; // Eg 'ch = b' b-a = 1 -> freq[1] = 1;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            freq[txt[j]-'a']--; // S2) Reduce the freq of curr character
            if(j-i+1 == k){
                if(allFreqZero(freq)) count++;
                freq[txt[i] -'a']++; // S4) Before moving ahead, update the freq to original
                i++;
            }
            j++;
        }
        return count;
    }
};


// Find All anagrams.
class Solution {
public:
    bool allFreqZero(vector<int>& freq){
        for(auto it: freq){
            if(it != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        vector<int> ans;
        vector<int> freq(26, 0);
        for(int i=0; i<k; i++){
            freq[p[i]-'a']++;
        }
        int i = 0; 
        int j = 0;
        while(j<n){
            freq[s[j]-'a']--;
            if(j-i+1 == k){
                if(allFreqZero(freq)) ans.push_back(i);
                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};