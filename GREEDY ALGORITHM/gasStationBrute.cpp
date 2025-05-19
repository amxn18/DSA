#include <bits/stdc++.h>
using namespace std;

//  LC 134 --> Brute Force TC--> O(n^2)
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            for(int i=0; i<n; i++){
                if(gas[i] < cost[i]) continue;
                int j =  (i+1)%n;
                int costForMovingFromIthStation = cost[i];
                int gasEarnedFromNextStationJ = gas[j];
    
                int currGas = gas[i] - costForMovingFromIthStation + gasEarnedFromNextStationJ;
                while(j != i){
                    if(currGas < cost[j]) break;
                    int costForMovingFromJ = cost[j];
                    j = (j+1)%n;
    
                    int gasEarnNextStationJ = gas[j];
                    currGas = currGas -  costForMovingFromJ + gasEarnNextStationJ;
                }
                if(j==i) return i;
            }
            return -1;
        }
    };