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
    for(int i=1; i<n; i++){
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

// 1) Insert Before Head
Node* insertBeforHead(Node* head, int val){
    Node* newNode = new Node(val);
    head->back = newNode;
    newNode->next = head;
    newNode->back = NULL;
    return newNode;
}

// 2) Insert Before Tail
Node* insertBeforeTail(Node* head, int val){
    Node* tail = head;
    while(tail->next != NULL){
        tail= tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val);
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = tail;
    tail->back = newNode;
    return head;
}
// 3) Insert Before Kth ELement
Node* insertBeforeKth(Node* head, int k, int val){
    Node* temp = head;
    int ctr = 0;
    while(temp!=NULL){
        ctr++;
        if(ctr==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
// 4) Insert Before Node(Node!=head)
void insertBeforeNode(Node* temp, int val){
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
}
int main(){
    vector<int> arr{10,20,30,40,50,60};
    Node* head = convertArrayToDll(arr);
    // head = insertBeforHead(head, 5);
    // head = insertBeforeTail(head, 70);
    print(head);
}
