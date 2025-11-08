#include <bits/stdc++.h>
using namespace std;

class maxHeap{
    public:
    vector<int> heap;

    void initializeHeap(){
        heap.clear();
    }

    void insert(int val){
        heap.push_back(val);
        int idx = heap.size() -1;
        while(idx > 0){
            int parent = (idx-1)/2;
            if(heap[parent < heap[idx]]){
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

        // Case 1 New val > old val --> bubble up
        if(val > oldVal){
            int i = idx;
            while(i > 0){
                int parent = (i-1)/2;
                if(heap[parent] < heap[i]){
                    swap(heap[parent], heap[i]);
                    i = parent;
                }
                else break;
            }
        }
        // Case 2 New val < old val --> heapify down
        else if(val < oldVal){
            heapifyDown(idx);
        }
    }

    void heapifyDown(int index){
        int n = heap.size();
        while(true){
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;

            if(left < n && heap[left] > heap[largest]) largest = left;
            if(right < n && heap[right] > heap[largest]) largest = right;
            if(largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

    void extractMax(){
        if(heap.size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax(){
        if(heap.size() == 0) return -1; 
        return heap[0];
    }

    bool isEmpty(){
        return heap.size() == 0;
    }

    int getSize(){
        return heap.size();
    }
};