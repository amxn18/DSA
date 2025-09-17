#include <bits/stdc++.h>
using namespace std;

// 1) Stack using Array
class stackUsingArray {
public:
    int top = -1;
    int st[1000];
    void push(int x) {
        top = top + 1;
        st[top] = x;
    }
    int peek() {  
        return st[top];
    }
    void pop() {
        top = top - 1;
    }
    int size() {
        return top + 1;
    }
};

// 2) Stack using LinkedList
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class stackUsingLinkedList{
    Node* top;
    int size = 0;
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }
    void pop(){
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int top(){
        return top->data;
    }
    int getSize(){
        return size;
    }
};


// 3) Stack using Queues (Lc 225)
class MyStack {
public: 
    queue<int> q;
    MyStack() {}
    
    void push(int x) {
        int s = q.size();
        q.push(x); // Push New Element
        // Rotate 
        for(int i=0; i<s; i++){
            q.push(q.front()); // Place Previous el at last
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};



