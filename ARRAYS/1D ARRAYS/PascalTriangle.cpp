#include <bits/stdc++.h>
using namespace std;


// Problem 1 --> Row and Column Given in Pascal's Triangle Find Out Element at that Position
// Instead of n!/r!*(n-r)! we can Modify the formula to save TC
int NCR(int n , int r){
    int res = 1;
    for(int i = 0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

// TC --> NCR --> O(r)
// SC --> O(1)


// Problem 2 --> Print the Nth Row of Pascal's Triangle

vector<int> printNthRow(int n){
    int ans = 1;
    vector<int> result;
    result.push_back(ans);
    for(int i=1; i<n; i++){
        ans = ans*(n-1);
        ans = ans/i;
        result.push_back(ans);
    }
    return result;

}

// TC --> O(n)
// SC --> O(n)


// Problem 3 --> Print the Pascal's Triangle till Nth Row
class Solution {
public:
    vector<int> generateRows(int n){
        int ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        for(int i = 1; i<n; i++){
            ans = ans*(n-i);
            ans = ans/i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1; i<=numRows; i++){
            result.push_back(generateRows(i));
        }
        return result;
    }
};

int main(){
    int n;
    cin>>n;
}