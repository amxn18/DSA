#include <bits/stdc++.h>
using namespace std;

// TC O(1), SC O(1)
class Solution{	
	public:
        int func(int n){
            if((n%4) == 1) return 1;
            else if ((n%4) == 2) return n+1;
            else if((n%4) == 3) return 0;
            else if((n%4) == 0) return n;
        }
		int findRangeXOR(int l,int r){
            return func(l-1)^func(r);
		}
};

// LC 1486. XOR Operation in an Array
// TC O(1), SC O(1)
class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= start + 2 * i;
        }
        return result;
    }
};