#include <bits/stdc++.h>
using namespace std;
// LC 3085
class Solution {
    public:
        int minimumDeletions(string word, int k) {
            vector<int> freq(26,0);
            for(char &ch : word){
                freq[ch-'a']++;
            }
            int result = word.length();
            for(int i=0; i<26; i++){
                int del = 0;
                for(int j =0; j<26; j++){
                    if(i==j) continue;
                    if(freq[j] < freq[i]){
                        del += freq[j];
                    } else if(abs(freq[j]-freq[i]) > k){
                        del += abs(freq[j]-freq[i]-k);
                    }
                }
                result = min(result, del);
                
            }
            return result;
        }
    };

//     # Problem: Minimum Deletions to Make Character Frequencies Unique
// # Approach:
// # 1. Count the frequency of each character in the string.
// # 2. Iterate through possible frequency values and calculate the minimum deletions required.
// # 3. If a character's frequency is less than the target, delete all occurrences.
// # 4. If a character's frequency is greater but the difference exceeds 'k', delete extra occurrences to maintain the 'k' condition.
// # 5. Return the minimum deletions required.

// # Time Complexity: O(26^2) ≈ O(1) (Since we have a fixed alphabet size)
// # Space Complexity: O(1) (Uses a fixed-size array of 26)
