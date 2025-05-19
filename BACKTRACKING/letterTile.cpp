#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int n;
    
        // Backtracking function to generate all possible tile sequences
        void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string& curr) {
            // Insert the current sequence into the set to ensure uniqueness
            result.insert(curr);
    
            // Iterate through all tiles
            for(int i = 0; i < n; i++) {
                // If the tile is already used, skip it
                if(used[i]) continue;
    
                // Mark tile as used
                used[i] = true;
    
                // Add tile to the current sequence
                curr.push_back(tiles[i]);
    
                // Recursive call to generate further sequences
                solve(tiles, used, result, curr);
    
                // Backtrack: Remove the last added tile and mark it as unused
                used[i] = false;
                curr.pop_back();
            }
        }
    
        int numTilePossibilities(string tiles) {
            n = tiles.length();
            
            // Boolean array to track used tiles
            vector<bool> used(n, false);
            
            // Set to store unique tile arrangements
            unordered_set<string> result;
            
            string curr = "";
            
            // Start backtracking
            solve(tiles, used, result, curr);
            
            return result.size() - 1; // Exclude the empty string
        }
    };
    
//    LC 1079 We generate all possible subsequences of the given string tiles using backtracking.

// We store sequences in an unordered_set to avoid duplicates.

// A boolean array used[] keeps track of tiles that are already included in the current sequence.

// In each recursive call:

// We add the sequence to the result set.

// We iterate through each tile.

// If it's not already used, we include it in the sequence and recurse.

// After recursion, we backtrack by removing the last tile and marking it as unused.

// The final result is the size of the set minus 1 (to exclude the empty string).