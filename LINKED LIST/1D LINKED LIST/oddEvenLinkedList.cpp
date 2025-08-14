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

// LC 328
// Method 1 Using Array
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) arr.push_back(temp->val);
        temp = head->next;
        while(temp != NULL && temp->next != NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) arr.push_back(temp->val);
        temp = head;
        int i=0;
        while(temp!=NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;

    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;  // Change Links
            even->next = even->next->next; // Change Links

            odd = odd->next;  // Move Odd Pointer
            even = even->next; // Move Even Pointer
        }
        odd->next = evenHead;  // Connect the end of odd list to the head of even list
        return head;
    }
};