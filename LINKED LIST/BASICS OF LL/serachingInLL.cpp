#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArraytoLL(vector<int>& arr){
    if (arr.empty()) return nullptr;
    // Head Creation
    Node* head = new Node(arr[0]);
    Node* traverser = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        traverser-> next = temp;
        traverser = temp;

    }
    return head;
}

bool searchInLL(Node* head, int key){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArraytoLL(arr);
    int key = 3;
    if(searchInLL(head, key)){
        cout << "Element " << key << " found in the Linked List." << endl;
    }   else{
        cout << "Element " << key << " not found in the Linked List." << endl;
    }  
}
