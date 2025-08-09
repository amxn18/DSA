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

// 1) Deletion at head
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
}
// 2) Deletion At tail
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back = NULL;
    prev->next = NULL;
    delete tail;
    return head;
}
// 3) Delete Kth Node
Node* deleteKthNode(Node* head ,int k){
    if(head == NULL) return NULL;
    int ctr = 0;
    Node* temp = head;
    while(temp!=NULL){
        ctr++;
        if(ctr==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == NULL || front == NULL){    // Single Element
        delete temp;
        return NULL;
    }
    else if(prev == NULL) deleteHead(head);
    else if(front == NULL) deleteTail(head);
    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
}

// 4) Delete Node (Node != head)
void deleteNode(Node* node){
    Node* prev = node->back;
    Node* front = node->next;
    if(front == NULL){
        prev->next = NULL;
        node->back = NULL;
        delete node;
        return;
    }
    prev->next = front;
    front->back = prev;
    node->next = node->back = NULL;
    delete node;
    return;
}
int main(){
    vector<int> arr{10,20,30,40,50,60};
    Node* head = convertArrayToDll(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthNode(head, 3);
    // deleteNode(head->next);
    print(head);
}