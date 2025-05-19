#include <bits/stdc++.h>
using namespace std;

//  LC 134 --> Brute Force TC--> O(n)
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            int totalGas = accumulate(begin(gas), end(gas), 0);
            int totalCost = accumulate(begin(cost), end(cost), 0);
    
            if(totalGas < totalCost) return -1;
            int total = 0;
            int resIndex = 0;
            for(int i=0; i<n; i++){
                total = total + gas[i] - cost[i];
                if(total<0){
                    resIndex = i+1;
                    total = 0;
                }
            }
            return resIndex;
        }
    };