#include <bits/stdc++.h>
using namespace std;

// Method 1 (Brute)
// TC O(3n) SC O(2n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0; 
        int total = 0;
        vector<int> leftMaxArray(n);
        leftMaxArray[0] = height[0];
        for(int i=1; i<n; i++){
            leftMaxArray[i] = max(leftMaxArray[i-1], height[i]);
        } 

        vector<int> rightMaxArray(n);
        rightMaxArray[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            rightMaxArray[i] = max(rightMaxArray[i+1], height[i]);
        }

        for(int i = 0; i<n; i++){
            int leftMax = leftMaxArray[i];
            int rightMax = rightMaxArray[i];
            total += min(leftMax, rightMax) - height[i];
        }
        return total;
    }
};

// Method 2 (Optimal)
// Tc O(n) SC O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int l = 0;
        int r = n-1;
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        while(l<r){
            if(height[l] < height[r]){
                if(lmax > height[l]) total += lmax-height[l];
                else lmax = height[l];
                l++;
            }
            else{
                if(rmax > height[r]) total += rmax-height[r];
                else rmax = height[r];
                r--;
            }
        }
        return total;
    }
};