#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        int i =0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        vector<int> res;
        while(i<n && j<m){
            if(a[i] < b[j]){
                if(res.empty() || res.back() != a[i]){   // add only unique
                    res.push_back(a[i]);
                    i++;
                }  
            }
            else if(a[i] > b[j]){
                if(res.empty() || res.back() != b[j]){
                    res.push_back(b[j]);
                    j++;
                }
            }
            else if(a[i] == b[j]){
                if(res.empty() || res.back() != b[j]){
                    res.push_back(b[j]);
                    j++;
                    i++;
                }
            }
        }
        while(i<n){
            if(res.empty() || res.back() != a[i]){   // add only unique
                    res.push_back(a[i]);
                    i++;
            }  
        }
        while(j<m){
            if(res.empty() || res.back() != b[j]){
                    res.push_back(b[j]);
                    j++;
            }
        }
        return res;
    }
};

// TC: O(n + m)
// SC: O(n + m) for result array