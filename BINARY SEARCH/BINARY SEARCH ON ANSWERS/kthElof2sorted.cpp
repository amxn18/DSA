#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if (n1 > n2) return kthElement(b, a, k);
        int low = max(k-n2, 0);
        int high = max(k, n1);
        int n = n1+n2;
        int left = k;
        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
            if(l1 <= l2 && l2 <= l1) return max(l1,l2);
            else if(l1 >l2) high = mid1-1;
            else low = mid1 + 1;
        }
        return 0;
    }
};