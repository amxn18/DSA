#include <bits/stdc++.h>
using namespace std;

// Method 1 (Sorting)
// TC --> O(nlogn)
// SC --> O(n)

vector<int> replaceWithRank(vector<int> &arr, int N) {
    vector<pair<int, int>> temp;
    for(int i=0; i<N; i++){
        temp.push_back({arr[i], i});
    }
    sort(temp.begin(), temp.end());
    vector<int> result(N);
    int rank = 1;
    for(int i=0; i<N; i++){
        int originalIdx = temp[i].second;
        result[originalIdx] = rank;
        rank++;
    }
    return result;
}


// Method 2 (Min Heap)
// TC --> O(nlogn)
// SC --> O(n)

vector<int> replaceWithRank(vector<int> &arr, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<N; i++){
        pq.push({arr[i], i});
    }

    vector<int> result(N);
    int rank = 1;
    for(int i=0; i<N; i++){
        auto p = pq.top();
        pq.pop();
        int originalIdx = p.second;
        result[originalIdx] = rank;
        rank++;
    }
    return result;
}
