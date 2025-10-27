#include <bits/stdc++.h>
using namespace std;

// Brute (Tc O(n^2) + O(n) SC O(2n))
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> knowsMe(n, 0); 
        vector<int> iKnow(n, 0);  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    knowsMe[j]++;  
                    iKnow[i]++;     
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            if (knowsMe[i] == n - 1 && iKnow[i] == 0)
                return i;
        }

        return -1;
    }
};


// TC O(2n) SC O(1)
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;
        while (top < down) {
            if (mat[top][down] == 1)
                top++;       
            else
                down--;      
        }
        int candidate = top;
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }
        return candidate;
    }
};
