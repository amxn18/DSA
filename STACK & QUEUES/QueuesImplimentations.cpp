#include <bits/stdc++.h>
using namespace std;

// 1) Queue using Array
class queueUsingArray {
    public:
    int size = 100;
    int q[100];
    int currsize = 0;
    int start = -1;
    int end = -1;
    void enqueue(int x){
        if(currsize == size){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(currsize == 0){
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % size;
        }
        q[end] = x;
        currsize++;
    }
    void dequeue(){
        if(currsize == 0){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        if(currsize == 1){
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % size;
        }
        currsize--;
    }
    int front(){
        if(currsize == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return q[start];
    }
    int getSize(){
        return currsize;
    }  
};

// 2) Queue using LinkedList

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class queueUsingLinkedList{
    Node* start;
    Node* end;
    int ssize = 0;
    void push(int x){
        Node* newNode = new Node(x);
        if(ssize == 0){
            start = newNode;
            end = newNode;
        }
        else {
            end->next = newNode;
            end = newNode;
        }
        ssize++;
    }
    void pop(){
        if(ssize == 0){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        ssize--;
    }
    int front(){
        if(ssize == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return start->data;
    }
    int getSize(){
        return ssize;
    }
};

// Queue using stack (LC 232)
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int topElement = s1.top();
        s1.pop();
        return topElement;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */





