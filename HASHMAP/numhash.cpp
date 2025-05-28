#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;  // size of the array
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];  // input elements of the array
    }

    // Precompute 
    int hash[13] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;  // count occurrences of each element
    }
    int q; // number of queries
    cout<<"Enter number of queries: ";
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter number to search: ";
        cin>>num;  // input the number to be searched
        cout<<hash[num]<<endl;  // output the count of occurrences
    }
    return 0;
}