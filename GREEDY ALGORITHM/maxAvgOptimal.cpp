#include <bits/stdc++.h>
using namespace std;

// LC 1792 --> TC O(m log n) m=extraStudents n= no of classes
class Solution {
    public:
        #define p pair<double,int>
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            int n = classes.size();
            // max heap {maxDiff, i}
            priority_queue<p> pq;
            for(int i=0; i<n; i++){
                double currPr = (double) classes[i][0]/classes[i][1];
                double newPr = (double) (classes[i][0]+1)/(classes[i][1]+1);
                double diff = newPr - currPr;
                pq.push({diff, i});
            }
            while(extraStudents--){
                // Max Pr at top
                auto curr = pq.top();
                pq.pop();
    
                double diff = curr.first;
                int idx = curr.second;
    
                // Add 1 student to both pass and total at each index
                classes[idx][0]++;
                classes[idx][1]++;
    
                double currPr = (double) classes[idx][0]/classes[idx][1];
                double newPr = (double) (classes[idx][0]+1)/(classes[idx][1]+1);
                diff = newPr - currPr;
                pq.push({diff, idx});
            }
            double result = 0.0;
            for(int i=0; i<n; i++){
                result += (double) classes[i][0]/ classes[i][1];
            }
            return result/n;
        }
    };