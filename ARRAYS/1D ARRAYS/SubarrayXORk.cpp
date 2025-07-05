#include <bits/stdc++.h>
using namespace std;

int subArrayWithXorK(vector<int>& nums, int k){
    int n = nums.size();
    map<int, int> mp;
    int xr = 0;
    int ctr = 0;
    mp[xr]++;
    for(int i=0; i<n; i++){
        xr = xr^nums[i];
        int x = xr^k;
        ctr += mp[x];
        mp[xr]++;
    }
    return ctr;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << "Number of subarrays with XOR equal to " << k << ": " << subArrayWithXorK(nums, k) << endl;
    return 0;
}

// TC --> O(n)
// SC --> O(1)