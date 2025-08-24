#include <bits/stdc++.h>
using namespace std;

// Method 1 : Using extra space
// TC --> O(n+n+nlogn)
// SC --> O(n)

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
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin(), vec.end());
        int i = 0;
        temp = head;
        while(temp != NULL){
            temp->val = vec[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};

// Method 2 : Using Merge Sort
// TC --> O(logn) for Sort + O(n) for merging 2 sorted LL + O(n/2) for finding middle node  --> TC --> O(nlogn)
// SC --> O(1)
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge2SortedLL(ListNode* leftHead, ListNode* rightHead){
        ListNode* t1 = leftHead;
        ListNode* t2 = rightHead;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
            if(t1) temp->next = t1;
            else temp->next = t2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* middleNode = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middleNode->next;
        middleNode->next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge2SortedLL(leftHead, rightHead);
    }
};