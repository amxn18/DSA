#include <bits/stdc++.h>
using namespace std;

// LC 649 TC--> (n)
class Solution {
    public:
        string predictPartyVictory(string senate) {
            queue<int> rQueue, dQueue;
            int n = senate.size();
    
            
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') rQueue.push(i);
                else dQueue.push(i);
            }
    
            
            while (!rQueue.empty() && !dQueue.empty()) {
                int rIdx = rQueue.front(); rQueue.pop();
                int dIdx = dQueue.front(); dQueue.pop();
    
                
                if (rIdx < dIdx) rQueue.push(rIdx + n); 
                else dQueue.push(dIdx + n);
            }

            return rQueue.empty() ? "Dire" : "Radiant";
        }
    };
    