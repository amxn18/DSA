#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// LC 61. Rotate List
// TC -> O(2N)
// SC -> O(1)
class Solution {
public:
    ListNode* findNth(ListNode* temp, int k){
        int ctr = 1;
        while(temp!=NULL){
            if(ctr == k) return temp;
            ctr++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){    // Step 1 Find length and tail
            len++;
            tail = tail->next;
        }
        if(k%len == 0) return head;
        k = k % len;  // If k is big eg k = 13 so k = 13%10 = 3 rotations
        tail->next = head; // Step 2 Make it circular
        ListNode* newLastNode = findNth(head, len-k);
        head = newLastNode->next; // Step 3 New head is next of new last node
        newLastNode->next = NULL; // Step 4 Break the circular
        return head;
    }
};