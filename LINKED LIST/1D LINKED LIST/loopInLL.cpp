#include <bits/stdc++.h>
using namespace std;

// LC 141
// Method 1 (Using Hashmap)
// TC O(N)
// SC O(N)


//   Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mp.find(temp) != mp.end()) return true;
            mp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};

// Method 2 (Using Floyd's Cycle Detection Algorithm)(Tortoise and Hare)
// TC O(N)
// SC O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};