#include <bits/stdc++.h>
using namespace std;

// Method 1 (Using Stack)
// TC O(2n)
// SC O(n)


class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        stack<int> st;
        DLLNode* temp = head;
        while(temp!=NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(!st.empty()){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Method 2 Reversing Links Single Traversal
// TC O(n)
// SC O(1)

// Using 2 Variables 
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
    DLLNode* curr = head;
    DLLNode* back = NULL;
    DLLNode* front = NULL;

    while (curr != NULL) {
        front = curr->next;

        curr->next = back;
        curr->prev = front;

        back = curr;
        curr = front;
    }
    return back;
}
};

// Using 1 Variable
DLLNode* reverseDLL(DLLNode* head) {
    DLLNode* last = NULL;
    DLLNode* curr = head;

    while (curr != NULL) {
        // Swap prev and next pointers for current node
        DLLNode* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Update last to current node (this will be new head eventually)
        last = curr;

        // Move curr forward to next node in original order (which is curr->prev after swap)
        curr = curr->prev;
    }

    // last now points to the new head after reversal
    return last;
}
