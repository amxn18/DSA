#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long MOD = 1000000007;
    long long pow(long long x, long long n){
        long long ans = 1.0;
        while(n){
            if(n%2 == 1){
                ans = (ans*x) % MOD;
                n = n-1;
            }
            else{
                x = (x*x) % MOD;
                n = n/2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evenIdx = (n+1)/2;
        long long oddIdx = n/2;

        long long a = pow(5, evenIdx);
        long long b = pow(4, oddIdx);

        return (int)((a*b) % MOD);
    }
};


// LC 1922
// TC: O(log n)
// SC: O(1) // No recursion stack space used