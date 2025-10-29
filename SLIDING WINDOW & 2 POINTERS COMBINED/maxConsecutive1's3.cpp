#include <bits/stdc++.h>
using namespace std;

// LC 1004
// Method 1: Brute Force TC ~ O(N^2) | SC ~ O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int zeros = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == 0) zeros++;
                if(zeros > k) break;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

// Method 2: (Better) Sliding Window + 2 Pointers TC ~ O(2N) | SC ~ O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0;
        int zeros = 0;
        for(int r=0; r<n; r++){
            if(nums[r] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};

// Method 3: (Optimal) Sliding Window + 2 Pointers TC ~ O(N) | SC ~ O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int maxLen = 0;
        int zeros = 0;
        for(int r=0; r<n; r++){
            if(nums[r] == 0) zeros++;
            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};