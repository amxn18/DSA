#include <bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
        TrieNode* children[2]; // two children for bit 0 and bit 1
        
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };
    
    class Solution {
    public:
        int findMaximumXOR(vector<int>& nums) {
            // Create the Trie root
            TrieNode* root = new TrieNode();
            
            // Function to insert a number into the Trie
            auto insert = [&](int num) {
                TrieNode* node = root;
                for (int i = 31; i >= 0; i--) { // Traverse 32 bits (for 32-bit numbers)
                    int bit = (num >> i) & 1;
                    if (node->children[bit] == nullptr) {
                        node->children[bit] = new TrieNode();
                    }
                    node = node->children[bit];
                }
            };
            
            // Function to find the maximum XOR of a number with the numbers already in the Trie
            auto findMaxXor = [&](int num) {
                TrieNode* node = root;
                int maxXor = 0;
                for (int i = 31; i >= 0; i--) {
                    int bit = (num >> i) & 1;
                    int oppositeBit = 1 - bit;
                    if (node->children[oppositeBit]) {  // If the opposite bit exists
                        maxXor |= (1 << i);  // Set the bit in maxXor
                        node = node->children[oppositeBit];
                    } else {
                        node = node->children[bit];
                    }
                }
                return maxXor;
            };
            
            int result = 0;
            // Insert the first number into the Trie
            insert(nums[0]);
            
            // Iterate through the numbers and calculate the maximum XOR
            for (int i = 1; i < nums.size(); i++) {
                // Update the result with the maximum XOR found
                result = max(result, findMaxXor(nums[i]));
                // Insert the current number into the Trie
                insert(nums[i]);
            }
            
            return result;
        }
    };
    