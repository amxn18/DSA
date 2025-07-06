#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1; // Nums1
        int j = n-1; // Nums2
        int k = m+n-1; // New Pointer To fill Nums1
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j])  nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j >= 0)  nums1[k--] = nums2[j--];  // Remaining Elemnts of Nums2 
    }
};


// LC // 88 - Merge Sorted Array
// TC --> O(m+n)
// SC --> O(1)