#include <bits/stdc++.h>
using namespace std;

void qs(int arr[], int low, int high){
    if(low<high){
        int pointer  = f(arr, low, high);
        qs(arr, low, pointer - 1);
        qs(arr, pointer + 1, high); 
    }
}

int f(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= arr[pivot] && i <= high) {
            i++;
        }
        while(arr[j] > arr[pivot] && j >= low) {
            j--;
        }
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    qs(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}