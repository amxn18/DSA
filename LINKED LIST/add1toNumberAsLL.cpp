#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// Method 1 
// TC --> O(N) + O(N) + O(N)
// SC --> O(1)
class Solution {
  public:
    Node* reverse(Node* head){
        if(head == NULL || head->next == NULL) return head;
        Node* newHead = reverse(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
        
    }
    Node* addOne(Node* head) {
       int carry = 1;
       head = reverse(head);
       Node* temp = head;
       while(temp != NULL){
           temp->data = temp->data + carry;
           if(temp->data < 10){
               carry = 0;
               break;
           }
           else{
               temp->data = 0;
               carry = 1;
           }
           temp = temp->next;
       }
       if(carry == 1){
           Node* newHead = new Node(1);
           head = reverse(head);
           newHead->next = head;
           return newHead;
       }
       return reverse(head);
    }
};

// Method 2 Optimal using Resursion
// TC --> O(N)
// SC --> O(N) (Recursion Stack)

class Solution {
  public:
    int findCarry(Node* temp){
        if(temp == NULL) return 1; // Base case
        int carry = findCarry(temp->next);
        temp->data = temp->data + carry;
        if(temp->data < 10) return 0; // carry = 0
        temp->data = 0;
        return 1; // carry 1
    }
    Node* addOne(Node* head) {
        int carry = findCarry(head);
        if(carry == 1){
            Node* newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
        return head; // carry = 0
    }
};