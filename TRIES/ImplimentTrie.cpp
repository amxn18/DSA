// LeetCode 208. Implement Trie (Prefix Tree)
// Time Complexity:
//   insert()    -> O(len)
//   search()    -> O(len)
//   startsWith() -> O(len)

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node* links[26];
        bool flag = false; // Indicates end of a word
    
        Node() {
            for(int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
    
        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }
    
        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }
    
        Node* get(char ch) {
            return links[ch - 'a'];
        }
    
        void setEnd() {
            flag = true;
        }
    
        bool isEnd() {
            return flag;
        }
    };
    
    class Trie {
    private:
        Node* root;
    
    public:
        // Constructor - initializes root node
        Trie() {
            root = new Node();
        }
    
        // Inserts a word into the trie
        void insert(string word) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++) {
                if (!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd(); // Marks end of the word
        }
    
        // Returns true if the word is in the trie
        bool search(string word) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++) {
                if (!node->containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }
    
        // Returns true if there is any word in the trie that starts with the given prefix
        bool startsWith(string prefix) {
            Node* node = root;
            for (int i = 0; i < prefix.length(); i++) {
                if (!node->containsKey(prefix[i])) {
                    return false;
                }
                node = node->get(prefix[i]);
            }
            return true;
        }
    };
    