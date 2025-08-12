#include <bits/stdc++.h>
using namespace std;

// LC 876 
// Method 1 (Traversal)
// TC : O(2n)
// SC : O(1)


//  * Definition for singly-linked list.
class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        int middleNode = (len/2) + 1;
        temp = head;
        while(temp != NULL){
            middleNode--;
            if(middleNode == 0) break;
            temp = temp->next;
        }
        return temp;
    }
};

// Method 2 (Tortoise and Hare) 2 Pointers
// TC : O(n/2)
// SC : O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};