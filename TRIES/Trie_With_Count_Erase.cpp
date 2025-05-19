#include <bits/stdc++.h> 
using namespace std;

/*
    Node class representing each character node in the Trie.
    Stores:
    - 26 possible character links (a-z)
    - Count of how many words end at this node (ew)
    - Count of how many words pass through this node (cp)
*/
class Node {
    Node* links[26];
    int ew = 0;  // Ends With
    int cp = 0;  // Count Prefix

public:
    // Checks if a character link exists
    bool containskey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // Returns the node linked with the character
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Creates a link for the character with a new node
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Increments count of words ending at this node
    void increaseEnd() {
        ew++;
    }

    // Increments count of prefixes passing through this node
    void increasePrefix() {
        cp++;
    }

    // Decrements the word end count when a word is erased
    void deleteEnd() {
        ew--;
    }

    // Decrements the prefix count during erase
    void reducePrefix() {
        cp--;
    }

    // Returns how many words end at this node
    int getEnd() {
        return ew;
    }

    // Returns how many words pass through this node
    int getPrefix() {
        return cp;
    }
};

/*
    Trie class implementing:
    - insert(word)
    - countWordsEqualTo(word)
    - countWordsStartingWith(prefix)
    - erase(word)
*/
class Trie {
private:
    Node* root;

public:
    // Constructor to initialize root node
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie
    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containskey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();  // increment prefix count at each node
        }
        node->increaseEnd();  // mark end of the word
    }

    // Returns how many times the word was inserted
    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containskey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getEnd();
    }

    // Returns how many words in the Trie start with the given prefix
    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containskey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    // Erases one occurrence of the word from the Trie
    void erase(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containskey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();  // decrement prefix count
            } else {
                return;  // word doesn't exist
            }
        }
        node->deleteEnd();  // decrement end count
    }
};
