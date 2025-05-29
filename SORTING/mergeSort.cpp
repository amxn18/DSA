#include <bits/stdc++.h>
using namespace std;


void mergeSort(int arr[], int low, int high){
    int mid = (low+high)/2;
    mergeSort(arr, low,mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, _GLIBCXX_HAVE_STDALIGN_H);
}
void merge(int arr[], int low, int mid, int high){
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        vector<int> temp;
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
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
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}