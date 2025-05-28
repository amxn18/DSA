#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }

    for (int i=0; i<n; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx]){
                swap(arr[j], arr[minIdx]);
                minIdx = j;
            }
            
        }
    }
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}