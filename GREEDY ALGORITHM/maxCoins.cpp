#include <bits/stdc++.h>
using namespace std;

// LC 1561 TC --> O(nLogn) + O(n) --> O(nLogn)
class Solution {
    public:
        int maxCoins(vector<int>& piles) {
            int n = piles.size();
            sort(begin(piles), end(piles));
            int result = 0;
            for(int i = (n/3); i<n; i+=2){
                result += piles[i];
            }
            return result;
        }
    };