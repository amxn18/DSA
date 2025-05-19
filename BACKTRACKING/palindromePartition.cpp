#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
    
        // Function to check if a substring s[l...r] is a palindrome
        bool isPalindrome(string& s, int l, int r){
            while(l < r){ // Compare characters from both ends
                if(s[l] != s[r]) return false; // If mismatch found, return false
                l++;
                r--;
            }
            return true; // If no mismatch, it's a palindrome
        }
    
        // Backtracking function to find all palindrome partitions
        void bt(string& s, int idx, vector<string>& curr, vector<vector<string>>& result){
            if(idx == n){ // If we have processed the entire string
                result.push_back(curr); // Add the current partitioning to the result
                return;
            }
    
            // Try all possible partitions starting from idx
            for(int i = idx; i < n; i++){
                if(isPalindrome(s, idx, i)){ // If the substring s[idx...i] is a palindrome
                    curr.push_back(s.substr(idx, i - idx + 1)); // Choose this partition
                    bt(s, i + 1, curr, result); // Recur for remaining part of the string
                    curr.pop_back(); // Undo the last choice (backtrack)
                }
            }
        }
    
        // Function to return all possible palindrome partitioning
        vector<vector<string>> partition(string s) {
            n = s.length();
            vector<vector<string>> result;
            vector<string> curr;
            bt(s, 0, curr, result); // Start backtracking from index 0
            return result;
        }
    };

//     # Problem: Palindrome Partitioning (Leetcode 131)
// # Given a string 's', we need to partition it into substrings such that 
// # every substring is a palindrome. Return all possible ways.

// # Approach:
// # 1. Use Backtracking to generate all possible partitions.
// # 2. At each step, check if the current substring (from idx to i) is a palindrome.
// # 3. If it is, add it to the current partition list and recurse for the remaining string.
// # 4. Once we reach the end of the string, add the current partition to the result.
// # 5. Backtrack by removing the last added partition and try another split.
// # 6. Use a helper function isPalindrome() to check if a given substring is a palindrome.

// # Complexity Analysis:
// # - Checking if a substring is a palindrome takes O(K) time, where K is the length of the substring.
// # - The total number of partitions can be around O(2^N) in the worst case.
// # - So the overall time complexity is approximately O(N * 2^N).

    