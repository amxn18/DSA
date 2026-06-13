#include <bits/stdc++.h>
using namespace std;

// Book Allocation Problem
// TC: O(Log(sum-max+1) * N) = O(NlogN)
class Solution {
  public:
    int findStudents(vector<int>& nums, int minPages){
        int students = 1;
        int studentsPage = 0;
        for(int i=0; i<nums.size(); i++){
            if(studentsPage + nums[i] <= minPages) studentsPage += nums[i];
            else{
                students++;
                studentsPage = nums[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int students = findStudents(arr, mid);
            if(students > k) low = mid+1; // need more pages 
            else high = mid-1; // need less pages
        }
        return low;
        
    }
};