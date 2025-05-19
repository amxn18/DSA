#include <bits/stdc++.h>
using namespace std;

// LC 3218/3219(long long result) 
class Solution {
    public:
        int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
            int x = horizontalCut.size();
            int y = verticalCut.size();
            // Sorting in descinding order
            sort(begin(horizontalCut), end(horizontalCut), greater<int>());
            sort(begin(verticalCut), end(verticalCut), greater<int>());
    
            int i=0; //horizontal cut
            int j=0; //vertical cut
    
            int hPieces = 1;
            int vPieces = 1;
    
            int result = 0;
    
            while(i<x && j<y){
                if(horizontalCut[i] > verticalCut[j]){
                    result += horizontalCut[i] * vPieces;
                    hPieces++;
                    i++;
                } else{
                    result += verticalCut[j] * hPieces;
                    vPieces++;
                    j++;
                }
            }
            while(i<x){
                result += horizontalCut[i] * vPieces;
                hPieces++;
                i++;
    
            }
            while(j<y){
                result += verticalCut[j] * hPieces;
                vPieces++;
                j++;
                
            }
            return result;
        }
    };

//     # Problem: Minimum Cost to Cut a Grid into Pieces
// # Approach: Greedy + Sorting

// # 1. Sort both horizontal and vertical cuts in descending order.
// # 2. Use two counters: 
// #    - hPieces (number of horizontal pieces)
// #    - vPieces (number of vertical pieces)
// # 3. Iterate through both lists:
// #    - Always pick the larger cut first to minimize cost.
// #    - Multiply the selected cut by the number of pieces in the opposite direction.
// # 4. Handle remaining cuts after one list is exhausted.

// # Time Complexity:
// # - O(N log N + M log M) for sorting
// # - O(N + M) for iterating through the cuts
// # - Overall: O((N + M) log (N + M))
