#include <bits/stdc++.h>
using namespace std;


// LC` 1539. Kth Missing Positive Number
// M1: O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        int i = 0;
        while(i < n && k > 0){
            if(arr[i] == num) i++;
            else k--;
            num++;
        }
        while(k--) num++; // {1,2,3} k = 2 -> OP = num = 5
        return num-1;
    }
};

// M2 O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] <= k)k++;
            else break;
        }
        return k;
    }
};
// M3 O(log N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k) low = mid+1;
            else high = mid-1;
        }
        return (high+1+k);
    }
};

