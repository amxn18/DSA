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

void print(Node* head){
    while(head != NULL){
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;
}

// 1) Insertion at head
Node* insertAtHead(Node* head, int val){
    Node* newHead = new Node(val);
    newHead->next = head;
    return newHead;
}

// 2) Insertion at tail
Node* insertAtTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newTail = new Node(val);
    temp->next = newTail;
    return head;
}

// 3) Insertion at kth 
Node* insertAtKth(Node* head, int el, int k){
    if(head == NULL){
        if(k==1) return new Node(el);
        else return NULL;
    }
    if(k==1){
        Node* newHead = new Node(el);
        newHead->next = head;
        return newHead;
    }
    int ctr = 0;
    Node* temp = head;
    while(temp != NULL){
        ctr++;
        if(ctr == (k-1)){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// 4) Insert Before Element X;
Node* insertBeforeX(Node* head, int X, int newElValue){
    if(head == NULL) return NULL;
    if(head->data == X){
        Node* newHead = new Node(newElValue);
        newHead->next = head;
        return newHead;
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == X){
            Node* newElement = new Node(newElValue);
            newElement->next = temp->next;
            temp->next = newElement;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr{10,20,30,40,50,60};
    Node* head =  convertArraytoLL(arr);
    // head = insertAtHead(head, 6);
    // head = insertAtTail(head, 70);
    // head = insertAtKth(head, 15, 2);
    print(head);
}