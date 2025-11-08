#include <bits/stdc++.h>
using namespace std;

class minHeap {
    public:
    vector<int> heap;
    void initializeHeap(){
        heap.clear();
    }

    void insert(int val){
        heap.push_back(val);
        int idx = heap.size() -1;
        while(idx > 0){
            int parent = (idx - 1)/2;
            if(heap[parent] > heap[idx]){
                swap(heap[parent], heap[idx]);
                idx = parent;
            }
            else break;
        }
    }

    void changeKey(int idx, int val){
        if(idx < 0 || idx >= heap.size()) return;
        int oldVal = heap[idx];
        heap[idx] = val;
        // Case 1 New val < old val --> bubble up
        if(val < oldVal){
            int i = idx;
            while(i>0){
                int parent = (i-1)/2;
                if(heap[parent] > heap[i]){
                    swap(heap[parent], heap[i]);
                    i = parent;
                }
                else break;
            }
        }
        // Case 2 New val > old val --> heapify down
        else if(val > oldVal){
            heapifyDown(idx);
        }
    }

    void heapifyDown(int idx){
        int n = heap.size();
        while(true){
            int leftChild = 2*idx+1;
            int rightChild = 2*idx +2;

            int smallest = idx;
            if(leftChild < n && heap[leftChild] < heap[smallest]) smallest = leftChild;
            if(rightChild < n && heap[rightChild] < heap[smallest]) smallest = rightChild;
            if(smallest == idx) break;

            swap(heap[smallest], heap[idx]);
            idx = smallest;
        }
    }

    void extractMin(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool isEmpty(){
        return heap.empty();
    }

    int getMin(){
        if(heap.empty()) return -1;
        return heap[0];
    }

    int heapSize(){
        return heap.size();
    }
};