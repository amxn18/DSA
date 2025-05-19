#include <bits/stdc++.h>
using namespace std;

// LC 1792 --> TC O(n^2) not optimal 
class Solution {
    public:
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            int n = classes.size();
            vector<double> pr(n);
            for(int i=0; i<n; i++){
                double ratio = (double) classes[i][0]/classes[i][1];
                pr[i] = ratio;
            }
            while(extraStudents != 0){
                vector<int> updatedPr(n);
                for(int i=0; i<n; i++){
                    double newRatio = (double)(classes[i][0] + 1)/(classes[i][1] + 1);
                    updatedPr[i] = newRatio;
                }
                int bestIdx = 0;
                double bestDiff = 0.0;
                for(int i=0; i<n; i++){
                    double diff = updatedPr[i] - pr[i];
                    if(diff > bestDiff){
                        bestDiff = diff;
                        bestIdx = i;
                    }
                }
                pr[bestIdx] = updatedPr[bestIdx];
                classes[bestIdx][0]++;
                classes[bestIdx][1]++;
            }
            // Average Ratio
            double result = 0;
            for(int i=0; i<n; i++){
                result += pr[i];
            } 
            return result/n;
        }
    };