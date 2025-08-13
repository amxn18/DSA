#include <bits/stdc++.h>
using namespace std;


// Method 1 Using Hashmap
// TC O(n)
// SC O(n)


class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        unordered_map<Node*, int> mp;
        Node* temp = head;
        int timer = 1;
        while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                int value = mp[temp];
                return timer-value;
            }
            mp[temp] = timer;
            timer++;
            temp = temp->next;
        }
    }
    // return 0;
};

// Method 2 
// TC O(n)
// SC O(1)

class Solution {
  public:
  
  
    int findLen(Node* slow, Node* fast){
        int ctr = 1;
        fast = fast->next;
        while(slow != fast){
            ctr++;
            fast = fast->next;
        }
        return ctr;
    }
    int lengthOfLoop(Node *head) {
        Node* slow = head; 
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return findLen(slow, fast);
        }
    }
    // return 0;
};
