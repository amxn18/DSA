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


// LC 19: Remove Nth Node From End of List
// Tc: O(2N)
// Sc: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        int ctr = 0;
        ListNode* temp = head;
        while(temp != NULL){
            ctr++;
            temp = temp->next;
        }
        if(ctr == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int res = ctr - n;
        temp = head;
        while(temp != NULL){
            res--;
            if(res == 0) break;
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};

// Method 2: Two Pointer Approach
// Tc: O(N)
// Sc: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        if(fast == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};