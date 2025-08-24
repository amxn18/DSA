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

// Method 1: Using Hashing
// TC --> O(N1* 1) + O(N2*1)
// SC --> O(N1) or O(N2)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* ,int> mp;
        ListNode* temp = headA;
        while(temp != NULL){
            mp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while(temp!= NULL){
            if(mp.find(temp) != mp.end()) return temp;
            temp = temp->next; 
        }
        return NULL;
    }
};

// Method 2: Using 2 pointer approach or list length Difference
// TC --> O(N1 + 2(N2))
// SC --> O(1)

class Solution {
public: 
    ListNode* findIntersection(ListNode* t1, ListNode* t2, int diffDist){
        while(diffDist){
            diffDist--;
            t2 = t2->next;
        }
        while(t1!=t2){
            t1 = t1->next;
            t2= t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int len1= 0;
        int len2 = 0;
        while(t1!=NULL){
            len1++;
            t1 = t1->next;
        }
        while(t2!=NULL){
            len2++;
            t2 = t2->next;
        }
        if(len1 < len2) return findIntersection(headA, headB, len2-len1);
        else return findIntersection(headB, headA, len1-len2);
    }
};


// Method 3: Using 2 pointer approach (Optimized)
// TC --> O(N1 + N2)
// SC --> O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB== NULL) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2) return t1;
            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1;
    }
};