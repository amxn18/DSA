#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    void deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == x){
                if(temp == head) head= head->next;
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if(nextNode) nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;
                delete temp;
                temp = nextNode;
            }
            else temp=temp->next;
        }
    }
};