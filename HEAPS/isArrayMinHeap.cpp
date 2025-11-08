#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<(n-2)/2; i++){
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;

        if(leftChild < n && nums[i] > nums[leftChild]){
            return false;
        }
        if(rightChild < n && nums[i] > nums[rightChild]){
            return false;
        }
    }
    return true;
}