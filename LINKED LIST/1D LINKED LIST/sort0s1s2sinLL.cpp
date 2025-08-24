#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Method 1 // 2 Passes
// TC --> O(2N)
// SC --> O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        int c0 =0;
        int c1 = 0;
        int c2 = 0;
        Node* temp= head;
        while(temp != NULL){
            if(temp->data == 0)c0++;
            else if(temp->data == 1)c1++;
            else if(temp->data == 2)c2++;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(c0){
                temp->data = 0;
                c0--;
            }
            else if(c1){
                temp->data = 1;
                c1--;
            }
            else{
                temp->data = 2;
                c2--;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Method 2 // 1 Pass
// TC --> O(N)
// SC --> O(1)

class Solution {
  public:
    Node* segregate(Node* head) {
       if(head == NULL || head->next == NULL) return head;
       Node* zeroHead = new Node(-1);
       Node* oneHead = new Node(-1);
       Node* twoHead = new Node(-1);
       Node* zero = zeroHead;
       Node* one = oneHead;
       Node* two = twoHead;
       Node* temp = head;
       while(temp != NULL){
           if(temp->data == 0){
               zero->next = temp;
               zero= temp;
           }
           else if(temp->data == 1){
               one->next = temp;
               one = temp;
           }
           else{
               two->next = temp;
               two = temp;
           }
           temp = temp->next;
       }
       zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
       one->next = twoHead->next;
       two-> next = NULL;
       
       Node* newHead = zeroHead->next;
       delete oneHead;
       delete twoHead;
       delete zeroHead;
       return newHead;
    }
};