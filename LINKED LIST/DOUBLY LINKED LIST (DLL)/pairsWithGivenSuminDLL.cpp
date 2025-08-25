#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

// Method 1 
// TC: O(n^2) SC: O(1)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* temp1 = head;
        vector<pair<int, int>> vec;
        while(temp1 != NULL){
            Node* temp2 = temp1->next;
            while(temp2 != NULL && (temp1->data + temp2->data) <= target){
                if(temp1->data + temp2->data == target) vec.push_back({temp1->data, temp2->data});
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return vec;
    }
};

// Method 2 Using Two Pointers
// TC: O(n)+O(n) 
// SC: O(1)

class Solution {
  public:
    Node* findTail(Node* head){
        Node* tail = head;
        while(tail->next != NULL) tail = tail->next;
        return tail;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        if(head == NULL) return ans;
        Node* left = head;
        Node* right = findTail(head);
        while(left->data < right->data){
            int sum = left->data + right->data;
            if(sum == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target) left = left->next;
            else right = right->prev;
        }
        return ans;
    }
};