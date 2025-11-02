#include <bits/stdc++.h>
using namespace std;

// LC 1358
// Method 1: Brute Force TC ~ O(N^2) | SC ~ O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ctr = 0;
        for(int i=0; i<n; i++){
            vector<int> hash(3, 0);
            for(int j=i; j<n; j++){
                hash[s[j] - 'a']++;
                if(hash[0] > 0 && hash[1] > 0 && hash[2] > 0){
                    ctr = ctr + (n - j);
                    break;
                }
            }
        }
        return ctr;
    }
};

// Method 2: Sliding Window + 2 Pointers TC ~ O(2N) | SC ~ O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastSeen(3, -1);
        int ctr = 0;
        for(int i=0; i<n; i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                ctr += (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
            }
        }
        return ctr;
    }
};