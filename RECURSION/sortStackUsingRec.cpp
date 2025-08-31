#include <bits/stdc++.h>
using namespace std;

void sort(stack<int>& s){
    if(s.empty()) return;
    int x = s.top();
    s.pop();
    sort(s);
    insert(s, x);
}

void insert(stack<int>& s, int x){
    if(s.empty() || s.top() <= x){
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insert(s, x);
    s.push(y);
}

// TC: O(N^2)
// SC: O(N) for recursion stack
