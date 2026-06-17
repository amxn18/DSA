#include <bits/stdc++.h>
using namespace std;

// LC 126: Word Ladder II
// Method 1 TC: O(N*L*P) where N is the number of words in the wordList, L is the length of each word and P is the number of paths from beginWord to endWord. SC: O(N*L) for storing all the words in the set and O(N*L) for storing all the sequences in the queue.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedStringOnLevel;
        usedStringOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        if(st.find(endWord) == st.end()) return ans;
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            // erase all the words used in previous level to transform
            if(vec.size() > level){ // New Level
                level++;
                for(auto it: usedStringOnLevel){
                    st.erase(it);
                }
            }
            string word = vec.back(); // last word
            if(word == endWord){
                if(ans.size() == 0) ans.push_back(vec); // First sequence 
                else if(ans[0].size() == vec.size()) ans.push_back(vec);
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch <= 'z'; ch++){
                    if(ch == original) continue;
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        vec.push_back(word); // append the word in the sequence
                        q.push(vec); // push the new sequence
                        usedStringOnLevel.push_back(word); // mark as visited on level
                        vec.pop_back(); // remove the added word to check another sequence
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};