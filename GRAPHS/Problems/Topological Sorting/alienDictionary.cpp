#include <bits/stdc++.h>
using namespace std;

// TC O(NL + K + E) where N is number of words, L is average length of each word, K is number of unique characters and E is number of ordering relations between characters
// SC O(K + E)
class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<bool> present(26, false);
        for(auto &word : words){
            for(char ch : word){
                present[ch-'a'] = true;
            }
        }
        int k = 0;
        for(int i=0; i<26; i++){
            if(present[i]) k++;
        }

        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adj[u].push_back(v);
                    indeg[v]++;
                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size()) return "";
        }

        queue<int> q;
        for(int i=0; i<26; i++){
            if(present[i] && indeg[i] == 0) q.push(i);
        }

        string ans = "";
        int ctr = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ctr++;
            ans.push_back(char(u + 'a'));
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }

        if(ctr != k) return "";
        return ans;
    }
};