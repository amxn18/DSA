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

int lengthOfLL(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }
    return length;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArraytoLL(arr);
    int length = lengthOfLL(head);
    cout << "Length of Linked List: " << length << endl;
}