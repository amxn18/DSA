#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(vector<int>& arr, int pages){
        int n = arr.size();
        long long pagesPerStudent = 0;
        int students = 1;
        for(int i=0; i<n; i++){
            if(pagesPerStudent + arr[i] <= pages){
                pagesPerStudent += arr[i];
            } else{
                students++;
                pagesPerStudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1; // No of students is more then no of books
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high){
            int mid =  low + (high-low)/2;
            int noOfStudents = solve(arr, mid);
            if(noOfStudents > k) low = mid+1;
            else high = low+1;
        }
        return low;
    }
};