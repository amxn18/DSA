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

// LC 25. Reverse Nodes in k-Group
// TC: O(N), SC: O(1)

class Solution {
public: 
    ListNode* findK(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kthNode = findK(temp, k);
            if(kthNode == NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head) head = kthNode;
            else prev->next=kthNode;
            prev=temp;
            temp = nextNode;
        }
        return head;
    }
};