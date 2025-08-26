#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

// Rotate a linked list
// Method 1 (Brute)
// TC --> O(n*m)*2 + O(xlogx) x is the total number of nodes
// SC --> O(2x)   x is the total number of nodes

class Solution {
  public:
    Node* convert(vector<int>& arr){
        if(arr.size() == 0) return NULL;
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i=1; i<arr.size(); i++){
            Node* newNode = new Node(arr[i]);
            temp->bottom = newNode;
            temp = temp->bottom;
        }
        return head;
    }
    Node *flatten(Node *root) {
       vector<int> arr;
       Node* temp = root;
       while(temp!=NULL){
           Node* t2 = temp;
           while(t2!=NULL){
               arr.push_back(t2->data);
               t2=t2->bottom;
           }
           temp = temp->next;
       }
       sort(arr.begin(), arr.end());
       root = convert(arr);
       return root;
    }
};

// Method 2 (Optimal)
// Before Optimal Code for Flatteing 2 Sorted Linked List
// TC --> O(n1+n2) n1 = size of first LL, n2 = size of second LL
// SC --> O(1)

class Solution {
  public:
  Node* flatten2SortedLL(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    Node* dummy = new Node(-1);
    Node* traverser = dummy;
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            traverser->bottom = l1;
            traverser = l1;
            l1 = l1->bottom;
        }
        else{
            traverser->bottom = l2;
            traverser = l2;
            l2 = l2->bottom;
        }
        traverser->next = NULL;
    }
    if(l1) traverser->bottom = l1;
    else traverser->bottom = l2;
    if(dummy->bottom) dummy->bottom->next = NULL; 
    return dummy->bottom;
  }
};


// Optimal Code for Flattening K Sorted Linked List
// TC --> O(n) * O(2m)  n = number of linked lists, m = average size of each linked list  2m = merging 2 sorted linked list
// SC --> O(n) for recursion stack
class Solution {
  public: 
    Node* merge(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    Node* dummy = new Node(-1);
    Node* res = dummy;
    
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            res->bottom = l1;
            res = l1;
            l1 = l1->bottom;  
        }
        else {
            res->bottom = l2;
            res = l2;
            l2 = l2->bottom; 
        }
        res->next = NULL;
    }
    
    if(l1) res->bottom = l1;
    else res->bottom = l2;
    
    return dummy->bottom;
}
    Node *flatten(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        Node* mergedHead = flatten(head->next);
        head = merge(head, mergedHead);
        return head;
    }
};