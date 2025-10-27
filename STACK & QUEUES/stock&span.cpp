#include <bits/stdc++.h>
using namespace std;

// LC 901 
// Method 1 
//TC O(no of days)
// SC(no of next calls)
class StockSpanner {
public:
    vector<int> list;
    StockSpanner() {
        
    }
    
    int next(int price) {
        list.push_back(price);
        int ctr = 1;
        for(int i=list.size()-2; i>=0; i--){
            if(list[i] <= price) ctr++;
            else break;
        }
        return ctr;
    }
};

// Method 2 (Previous Smaller Element Approach)
// TC O(2n) n= no of days
// SC O(n) for stack
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = -1;
    StockSpanner() {
        idx =-1;
    }
    
    int next(int price) {
        idx = idx + 1;
        while(!st.empty() && st.top().first <= price)st.pop();
        int ans = idx - (st.empty() ? -1 : st.top().second);
        st.push({price, idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

