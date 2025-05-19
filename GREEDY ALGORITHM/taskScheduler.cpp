#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            // Vector containg A to Z
            vector<int> mp(26, 0);
            // Storing Freq 
            for(char &ch : tasks){
                mp[ch-'A']++;
            }
            sort(begin(mp), end(mp));
            int maxFreq = mp[25];
            int empty = maxFreq -1;
            int idleSlots = n*empty;
            for(int i =24; i>=0; i--){
                idleSlots -= min(mp[i], empty);
            }
            if(idleSlots > 0) return tasks.size() + idleSlots;
            return tasks.size();
        }
    };

//     # Task Scheduler (Leetcode 621)

// # 1. Create a frequency array 'mp' of size 26 to store the count of each task (A-Z).
// # 2. Sort the frequency array to get the most frequent task at the end (mp[25]).
// # 3. Calculate the maximum frequency 'maxFreq' of any task.
// # 4. Compute the number of empty slots needed using formula: (maxFreq - 1).
// # 5. Multiply empty slots by 'n' (cooldown time) to get total idle slots.
// # 6. Reduce idle slots by filling them with other tasks from mp[24] to mp[0].
// # 7. If idle slots remain, return total tasks + idle slots. Otherwise, return total tasks.
