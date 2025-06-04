#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1) mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
// LC// 75 - Sort Colors (Optimal)
// TC --> O(n)
// SC --> O(1)

// Explanation:
// The Dutch National Flag problem is a classic algorithmic problem that involves sorting an array of three distinct values (in this case, 0s, 1s, and 2s) in a single pass.
// The algorithm uses three pointers: `low`, `mid`, and `high`.
// - `low` points to the next position for 0s.
// - `mid` is the current element being examined.
// - `high` points to the next position for 2s.
// The algorithm iterates through the array, swapping elements as necessary to ensure that all 0s are at the beginning, all 1s are in the middle, and all 2s are at the end.
// The key idea is to maintain the invariant that all elements before `low` are 0s, all elements between `low` and `mid` are 1s, and all elements after `high` are 2s.