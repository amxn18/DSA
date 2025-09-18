#include <bits/stdc++.h>
using namespace std;

// LC 155
// M1 Tc O(1) Sc O(2n)
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


// M2 Tc O(1) Sc O(n)

class MinStack {
public:
     stack<long long> st;
    long long minElement;
    MinStack() {
        
    }
    
    void push(int val) {
         if (st.empty()) {
            minElement = val;
            st.push(val);
        } else {
            if (val >= minElement) {
                st.push(val);
            } else {
                st.push(2LL * val - minElement);
                minElement = val;
            }
        }
    }
    
    void pop() {
         if (st.top() < minElement) {
            minElement = 2LL * minElement - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.top() >= minElement) {
            return st.top();
        } else {
            return minElement;
        }
    }
    
    int getMin() {
        return minElement;
    }
};
