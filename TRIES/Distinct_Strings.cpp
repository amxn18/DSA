#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        Node* links[26];
        int count = 0; // Counts how many times a substring appears
        
        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
    
        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }
    
        Node* get(char ch) {
            return links[ch - 'a'];
        }
    
        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }
    };
    
    int countDistinctSubstrings(string &s) {
        int ctr = 0;
        Node* root = new Node();
    
        // Iterate over each suffix starting from index i
        for (int i = 0; i < s.length(); i++) {
            Node* node = root; // Start from the root for each suffix
            
            // Process each character in the suffix starting from i
            for (int j = i; j < s.length(); j++) {
                // If the character is not in the Trie, insert it and count the substring
                if (!node->containsKey(s[j])) {
                    node->put(s[j], new Node());
                    ctr++; // Increment count whenever a new substring is found
                }
                // Move to the next level in the Trie
                node = node->get(s[j]);
            }
        }
    
        return ctr + 1; // Add 1 for the empty substring
    }
    

    // 1. Outer loop (for (int i = 0; i < s.length(); i++)):
    // This loop iterates through each starting point of a suffix in the string.
    
    // Each time, you start a new suffix from index i to the end of the string. For example, if your string is "abc", the suffixes are "abc", "bc", and "c".
    
    // 2. Inner loop (for (int j = i; j < s.length(); j++)):
    // This loop iterates through all possible substrings that start from index i and extend to the right.
    
    // For each character in the suffix, you insert that character into the Trie and move to the next level of the Trie.
    
    // It ensures that you insert substrings of varying lengths, starting from just the first character of the suffix, then the first two characters, and so on.
    