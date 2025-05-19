#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
    
            // Step 1: Transpose the matrix
            // Swap matrix[i][j] with matrix[j][i] for all i < j
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
    
            // Step 2: Reverse each row
            // This gives the final rotated matrix
            for (int i = 0; i < n; i++) {
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
    };
    // 🧨 LeetCode 48: Rotate Image

    // 🧠 Problem:
    // You are given an n x n 2D matrix representing an image. 
    // Rotate the image by 90 degrees (clockwise), in-place.
    
    // 🔧 Approach:
    // 1. **Transpose the matrix**:
    //    - Swap elements across the diagonal: matrix[i][j] ↔ matrix[j][i]
    // 2. **Reverse each row**:
    //    - This completes the clockwise rotation.
    
    // Why it works:
    // - Transposing flips rows and columns.
    // - Reversing rows reorients the columns into rotated rows.
    
    // ⏱ Time Complexity: O(n^2)
    // - Each element is visited once during transpose and once during reversal.
    
    // 💾 Space Complexity: O(1)
    // - Rotation is done in-place with no extra space used.
    