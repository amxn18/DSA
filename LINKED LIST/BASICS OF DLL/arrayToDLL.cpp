#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
        back = NULL;
    }

};

Node* convertArrayToDll(vector<int>& arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=0; i<n; i++){
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr {10,20,30,40,50,60};
    Node* head = convertArrayToDll(arr);
}