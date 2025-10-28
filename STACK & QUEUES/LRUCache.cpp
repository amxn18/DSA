#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    class Node{
        public:
        int k;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int value){
            k = key;
            val = value;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addAfterHeadLRU(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        int res = node->val;
        deleteNode(node);
        addAfterHeadLRU(node);
        mp[key] = head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            addAfterHeadLRU(node);
        }
        if(mp.size() == key){
            Node* node = tail->prev;
            mp.erase(node->k);
            deleteNode(node);
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addAfterHeadLRU(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */