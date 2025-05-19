#include <bits/stdc++.h>
using namespace std;

// LC 649 TC--> (n)
class Solution {
    public:
        string predictPartyVictory(string senate) {
            queue<int> rQueue, dQueue;
            int n = senate.size();
    
            // Step 1: Store initial indices of Radiant and Dire senators
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') rQueue.push(i);
                else dQueue.push(i);
            }
    
            // Step 2: Process rounds until one party is eliminated
            while (!rQueue.empty() && !dQueue.empty()) {
                int rIdx = rQueue.front(); rQueue.pop();
                int dIdx = dQueue.front(); dQueue.pop();
    
                // The senator with the smaller index bans the other
                if (rIdx < dIdx) rQueue.push(rIdx + n); // Radiant wins, push back
                else dQueue.push(dIdx + n); // Dire wins, push back
            }
    
            // Step 3: The non-empty queue determines the winner
            return rQueue.empty() ? "Dire" : "Radiant";
        }
    };
    