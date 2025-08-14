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

// LC 2095
// Method 1 (Two Pass Approach):
// Tc: O(N) + O(N/2)
// Sc: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        int ctr = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            ctr++;
            temp = temp->next;
        }
        int res = ctr/2;
        temp = head;
        while(temp!=NULL){
            res--;
            if(res==0){
                ListNode* middle = temp->next;
                temp->next = temp->next->next;
                delete middle;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Method 2 Two Pointer Approach:
// Tc: O(N)
// Sc: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode;
        return head;
    }
};