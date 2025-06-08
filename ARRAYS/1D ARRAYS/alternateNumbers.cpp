#include <bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int>& nums){
    int n = nums.size();
    vector<int> posi;
    vector<int> negi;
    for(int i=0; i<n; i++){
        if(nums[i] >=0){
            posi.push_back(nums[i]);
        } else {
            negi.push_back(nums[i]);
        }
    }
    if(posi.size() > negi.size()){
        for(int i=0; i<negi.size(); i++){
            nums[2*1] = posi[i];
            nums[2*i+1] = negi[i];
        }
        int idx = negi.size()*2;
        for(int i=negi.size(); i<posi.size(); i++){
            nums[idx++] = posi[i];
        }
    } else{
        for(int i=0; i<posi.size(); i++){
            nums[2*1] = posi[i];
            nums[2*i+1] = negi[i];
        }
        int idx = posi.size()*2;
        for(int i=posi.size(); i<negi.size(); i++){
            nums[idx++] = negi[i];
        }
    }
    return nums;
}

// Alternate Numbers(No of Positive and Negative Numbers are not equal)
// TC --> O(2n)
// SC --> O(n)