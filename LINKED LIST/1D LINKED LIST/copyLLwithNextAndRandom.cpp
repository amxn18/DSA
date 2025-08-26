#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// LC 138: Copy Linked List with Next and Random Pointer
// Method 1 (Using Hashing)
// TC --> O(2n)
// SC --> O(n) for map + O(n) for new LL

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mp;
        while(temp != NULL){
            Node* newNode = new Node(temp->val);  // Node of Copied LL
            mp[temp] = newNode; // Store Both Original Node With Its Copied Node
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            Node* copiedNode = mp[temp];
            copiedNode->next = mp[temp->next];    // Copied Node's Next Should Point to Copied Node of Original Node's Next
            copiedNode->random = mp[temp->random]; // Copied Node's Random Should Point to Copied Node of Original Node's Random
            temp = temp->next;
        }
        return mp[head]; // Head of Copied LL
    }
};

// Method 2 (Without Using Extra Space)
//
class Solution {
public:
    void insertCopy(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copiedNode = new Node(temp->val);
            copiedNode->next = temp->next;
            temp->next = copiedNode;
            temp = temp->next->next;
        }
    }
    
    void connectRandomPointer(Node* head){
        Node* temp = head;
        while(temp != NULL && temp->next != NULL){  
            Node* copiedNode = temp->next;
            if(temp->random) {
                copiedNode->random = temp->random->next;
            } else {
                copiedNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }
    
    Node* getCopyList(Node* head){
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;
        
        while(temp != NULL){
            res->next = temp->next;
            res = res->next;

            if(temp->next != NULL) {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        insertCopy(head);
        connectRandomPointer(head);
        return getCopyList(head);
    }
};