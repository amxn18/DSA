#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int>& s){
    if(s.empty()) return;
    int x = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, x);
}

void insertAtBottom(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);
}

// TC: O(N^2)
// SC: O(N) for recursion stack
