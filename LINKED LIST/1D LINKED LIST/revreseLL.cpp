#include <bits/stdc++.h>
using namespace std;

// LC 206
// Method 1 : Using stack
// TC : O(2n)
// SC : O(n)

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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!st.empty()){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Method 2 : Iterative
// TC : O(n)
// SC : O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;  // Pointer reversal
            prev = temp;   // Move prev to current node
            temp = front;  // Move to the next node
        }
        return prev;
    }
};

// Method 3 : Recursive
// TC : O(n)
// SC : O(n) (due to recursion stack)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};