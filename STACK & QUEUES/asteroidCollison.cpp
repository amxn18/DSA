#include <bits/stdc++.h>
using namespace std;

// LC 735. Asteroid Collision
// TC: O(N), SC: O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &a : asteroids){
            while(!st.empty() && st.top()>0 && a<0){
                int sum = a + st.top();
                if(sum < 0) st.pop();
                else if(sum > 0) a=0;
                else{
                    st.pop();
                    a=0;
                }
            }
            if(a!=0) st.push(a);
        }
        int s = st.size();
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()){
            result[i] = st.top();
            st.pop();
            i--;
        }
        return result;

    }
};