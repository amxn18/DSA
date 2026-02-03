#include <bits/stdc++.h>
using namespace std;

// LC: 403. Frog Jump
// Method 1 : Recursion TC: O(3^n) SC: O(n)
class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    bool solve(vector<int>& stones, int currStoneIdx, int prevJump){
        if(currStoneIdx == n-1) return true;
        bool result = false;
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++){
            if(nextJump > 0){
                int nextStone = stones[currStoneIdx] + nextJump;
                if(mp.find(nextStone) != mp.end()) result = result || solve(stones, mp[nextStone], nextJump);
            }
        }
        return result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1) return false;
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        return solve(stones, 0, 0);
    }
};

// Method 2 : DP + Memoization TC: O(n^2) SC: O(n^2)
class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    bool solve(vector<int>& stones, int currStoneIdx, int prevJump){
        if(currStoneIdx == n-1) return true;
        if(t[currStoneIdx][prevJump] != -1) return t[currStoneIdx][prevJump];
        bool result = false;
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++){
            if(nextJump > 0){
                int nextStone = stones[currStoneIdx] + nextJump;
                if(mp.find(nextStone) != mp.end()) result = result || solve(stones, mp[nextStone], nextJump);
            }
        }
        return t[currStoneIdx][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1) return false;
        memset(t, -1, sizeof(t));
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        return solve(stones, 0, 0);
    }
};