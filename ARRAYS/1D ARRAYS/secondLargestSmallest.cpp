#include <bits/stdc++.h>
using namespace std;

int seconLargest(int arr[], int n){
    int l = arr[0];
    int sl = -1;
    for(int i=0; i<n; i++){
        if(arr[i] > l ){
            sl = l;
            l = arr[i];
        } else if(arr[i] < l && arr[i] > sl){
             sl = arr[i];
        }
    }
    return sl;
}

int seconSmallest(int arr[], int n){
    int s = arr[0];
    int ss = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] < s){
            ss = s;
            s = arr[i];
        } else if(arr[i] != s && arr[i] < ss){
            ss = arr[i];
        }
    }
    return ss;
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
    
    int largest = seconLargest(arr, n);
    int smallest = seconSmallest(arr, n);
    
    cout << "Second Largest Element: " << largest << endl;
    cout << "Second Smallest Element: " << smallest << endl;
    
    return 0;
}

// # TC and SC:
// Time Complexity: O(n) for both finding second largest and second smallest elements.
// Space Complexity: O(1) as we are using a constant amount of extra space.