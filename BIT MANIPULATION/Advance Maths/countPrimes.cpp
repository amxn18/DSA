#include <bits/stdc++.h>
using namespace std;

// LC 204. Count Primes
// Method: Sieve of Eratosthenes
// TC O(n log log n), SC O(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<int> Prime(n, 1); 
        for(int i=2; i*i<n; i++){ 
            if(Prime[i] == 1){
                for(int j = i*i; j<n; j+=i) Prime[j] = 0; 
            }
        }
        int ctr = 0;
        for(int i = 2; i<n; i++){ 
            if(Prime[i] == 1) ctr++;
        }
        return ctr;
    }
};
