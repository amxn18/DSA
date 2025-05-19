#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag = false;

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
    Trie() {
        root = new Node();
    }

    // Inserts a string into the Trie
    void insertStr(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(); // Mark the end of the word
    }

    // Checks if the word's prefix exists in the Trie and all its prefixes are complete
    bool prefixExists(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                if (!node->isEnd()) {
                    return false; // A prefix must also be a complete word
                }
            } else {
                return false; // If the character is not found, return false
            }
        }
        return true;
    }
};

// Function to find the longest "complete string" from the list
string completeString(int n, vector<string> &a) {
    Trie obj;

    // Insert all strings into the Trie
    for (auto &it : a) {
        obj.insertStr(it);
    }

    string longest = "";

    // Check each string in the list
    for (auto &it : a) {
        if (obj.prefixExists(it)) {
            // If the string has all its prefixes, check if it's the longest or lexicographically smallest
            if (it.length() > longest.length() || (it.length() == longest.length() && it < longest)) {
                longest = it;
            }
        }
    }

    // If no valid string is found, return "None"
    if (longest == "") return "None";
    return longest;
}