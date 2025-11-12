#include <bits/stdc++.h>
using namespace std;

// LC 846: Hand of Straights
// TC O(nlogk)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        unordered_map<int, int> mp;
        for(auto h: hand){
            mp[h]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it : mp){
            pq.push(it.first);
        }
        while(!pq.empty()){
            int start = pq.top();
            pq.pop();
            if(mp[start] == 0) continue;
            int ctr = mp[start];
            for(int i=0; i<groupSize; i++){
                int nextCard = start + i;
                if(mp[nextCard] < ctr) return false;
                mp[nextCard] -= ctr;
            }
        }
        return true;
    }
};