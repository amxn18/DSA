#include <bits/stdc++.h>
using namespace std;


// TC -> O((2^n)*n)
// SC -> O(n) + O(n)  (Recursion Stack Space + Temporary Array)
vector<vector<int>> result;
void f(int idx, vector<int>&nums, vector<int>& temp, int sum){
    int n = nums.size();
    int currSum = 0;
    if(idx == n){
        if(currSum == sum){
            result.push_back(temp);
        }
    }
    temp.push_back(nums[idx]);
    currSum += nums[idx];
    f(idx+1, nums, temp, sum); // Take
    temp.pop_back();
    sum -= nums[idx];
    f(idx+1, nums, temp, sum); // Not Take
}
vector<vector<int>> allSubsequenceSumK(vector<int> nums, int sum){
    vector<int> temp;
    f(0, nums, temp, sum);
    return result;
}

// Follow Up --> Count the number of subsequences with sum k
// TC -> O(2^n)
// SC -> O(n) (Recursion Stack Space)
int f(int idx, vector<int>& nums, int sum) {
    int n = nums.size();

    // Base case
    if(idx == n) {
        if(sum == 0) return 1;
        return 0;
    }

    int take = f(idx+1, nums, sum - nums[idx]);
    int notTake = f(idx+1, nums, sum);
    return take + notTake;
}

int countSubsequenceSumK(vector<int> nums, int k) {
    return f(0, nums, k);
}

// Next Follow Up --> Check if there exists a subsequence with sum k
// TC -> O(2^n)
// SC -> O(n) (Recursion Stack Space)
class Solution {
public:
    bool existsSubsequence(int idx, vector<int>& nums, int currSum, int k) {
        int n = nums.size();
        // base case
        if(idx == n) {
            if(currSum == k) return true;
            else return false;
        }
        // take current element
        if(existsSubsequence(idx + 1, nums, currSum + nums[idx], k)) return true;
        // not take current element
        if(existsSubsequence(idx + 1, nums, currSum, k)) return true;
        return false; // no valid subsequence found in either branch
    }

    bool isSubsequenceSumK(vector<int>& nums, int k) {
        return existsSubsequence(0, nums, 0, k);
    }
};

// Next Follow Up --> Print any one subsequence with sum k
// TC -> O(2^n)
// SC -> O(n) (Recursion Stack Space + Temporary Array)
bool func(int idx, vector<int>& nums, vector<int>& temp, int sum) {
    int n = nums.size();

    // Base case
    if(idx == n) {
        if(sum == 0) {
            for(auto it : temp) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    temp.push_back(nums[idx]);
    if(func(idx+1, nums, temp, sum - nums[idx])) return true; // Take
    temp.pop_back();
    if(func(idx+1, nums, temp, sum)) return true; // Not Take
    return false;
}

void printOneSubsequenceSumK(vector<int> nums, int sum) {
    vector<int> temp;
    func(0, nums, temp, sum);
}
