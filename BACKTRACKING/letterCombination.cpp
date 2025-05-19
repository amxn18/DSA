#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> result;  // Stores all possible letter combinations
    
        // Backtracking function to generate letter combinations
        void solve(int idx, string& digits, string& temp, unordered_map<char, string>& mp) {
            // Base Case: If we have processed all digits, store the generated combination
            if (idx >= digits.length()) {
                result.push_back(temp);
                return;
            }
    
            // Get the characters corresponding to the current digit
            char ch = digits[idx];  
            string str = mp[ch];  
    
            // Try each character mapped to the current digit
            for (int i = 0; i < str.length(); i++) {
                temp.push_back(str[i]);  // Add character to current combination
                solve(idx + 1, digits, temp, mp);  // Recur for the next digit
                temp.pop_back();  // Backtracking step to explore new possibilities
            }
        }
    
        // Main function to generate letter combinations
        vector<string> letterCombinations(string digits) {
            if (digits.length() == 0) {  // Edge case: Empty input
                return {};
            }
    
            // Mapping of digits to corresponding letters (like a phone keypad)
            unordered_map<char, string> mp;
            mp['2'] = "abc"; mp['3'] = "def"; mp['4'] = "ghi"; mp['5'] = "jkl";
            mp['6'] = "mno"; mp['7'] = "pqrs"; mp['8'] = "tuv"; mp['9'] = "wxyz";
    
            string temp = "";  // Temporary string to build combinations
            solve(0, digits, temp, mp);  // Start backtracking
            return result;  // Return all valid letter combinations
        }
    };
    // Leetcode 17 (Letter Combinations of a Phone Number).

    // # Step 1: Define a recursive function `solve` to generate letter combinations.
    // # - It takes an index, input digits, a temporary string, and a digit-to-letters map.
    
    // # Base Case:
    // # - If all digits are processed, store the generated string in `result`.
    
    // # Step 2: Get the possible letters for the current digit.
    // # - For example, '2' -> "abc", '3' -> "def", etc.
    
    // # Step 3: Iterate through the mapped characters.
    // # - Append each character to `temp` and move to the next digit recursively.
    
    // # Step 4: Implement Backtracking.
    // # - After recursive call, remove the last character (`pop_back()`) to explore new combinations.
    
    // # Edge Case:
    // # - If `digits` is empty, return an empty list.
    
    // # Time Complexity: O(4^n) (worst case, when all digits have 4 possible letters).
    // # Space Complexity: O(n) (recursion stack depth).
    
    // # This approach efficiently generates all possible letter combinations.
    