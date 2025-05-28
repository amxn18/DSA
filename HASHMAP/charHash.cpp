#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    
    //Precompute
    int hash[256] = {0};
    for(int i=0; i<s.length(); i++){
        hash[s[i]]++;
    }
    int q;
    cout<<"Enter number of queries: ";
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter character to count: ";
        cin>>ch;
        cout<<"Count of '"<<ch<<"' in the string: ";
        cout<<hash[ch]<<endl;
    }
    return 0;
}