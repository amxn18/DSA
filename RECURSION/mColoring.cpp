#include <bits/stdc++.h>
using namespace std;

// TC --> O(n^m) where n is no of nodes and m is no of colors
// SC --> O(n) for colors array + O(n) for recursion stack
class Solution {
  public:
    bool isSafe(vector<vector<int>>& edges, vector<int>& colors, int currNode, int noOfNodes, int currColor){
        for(int k = 0; k<noOfNodes; k++){
            if(k != currNode && edges[k][currNode] == 1 && colors[k] == currColor) return false;
        }
        return true;
    }
    bool isPossible(vector<vector<int>>& edges, vector<int>& colors, int noOfColors, int noOfNodes, int currNode){
        if(currNode == noOfNodes) return true;
        for(int i=1; i<=noOfColors; i++){
            if(isSafe(edges, colors, currNode, noOfNodes, i)){
                colors[currNode] = i;
                if(isPossible(edges, colors, noOfColors, noOfNodes, currNode+1)) return true;
                colors[currNode] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> colors(v, 0);
        if(isPossible(edges, colors, m, v, 0)) return true;
        return false;
    }
};