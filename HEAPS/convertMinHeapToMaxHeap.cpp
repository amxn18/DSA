#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i){
    int largest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    if(leftChild < n && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if(rightChild < n && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void convert(vector<int>& arr){
    int n = arr.size();
    for(int i=(n-2)/2; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}