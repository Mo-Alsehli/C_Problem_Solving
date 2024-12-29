#include <iostream>
using namespace std;


struct Node {
    int value;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList(): head(NULL){}

    void prepend(int value){
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    void append(int value){
        Node* newNode = new Node();
        newNode->value = value;

        if(!head){
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void deleteValue(int value){
        if(head == nullptr)
            return;
        if(head->value == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while(curr->next != nullptr && curr->next->value != value){
            curr = curr->next;
        }

        if(curr->next == nullptr)
            return;

        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

    }

    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

};

/* 
- Stack: Stack is the fundamental linear data structures used in the computer science to store collections of the objects. It can operate on the Last In First Out (LIFO) Principle.
*/

class Stack{
private:
    int top;
    int arr[100];

public:
    Stack() {top=-1;}

    void push(int value){
        if(top >= 99){
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++top] = value;
        cout << "Pushed: " << value << " Into Stack\n";
    }

    int pop(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return 0;
        }

        return arr[--top];
    }

    int peek(){
        if(top < 0){
            cout << "Stack Is Empty" << endl;
            return 0;
        }

        return arr[top];
    }

    void display(){
        if(top < 0){
            cout << "Stack Is Empty" << endl;
            return;
        }

        int i = 0;

        for(i = 0; i <= top; i++){
            cout << arr[i] << " | " ;
        }

        cout << endl;
    }

};


/*
-- Queue: it's a linear data structure that consists of elements arranged in a sequential order where one end is used to add elements and another for removing them which results in the FIFO ( First-In-First-Out ) Order of operation.
*/

#define MAX_SIZE 100

class Queue {
public:
    int front;
    int rear;
    int arr[MAX_SIZE];

    Queue(): front(-1), rear(-1){}

    bool isEmpty() {return front == -1 || front > rear;}
    bool isFull() {return rear == MAX_SIZE - 1;}

    void enqueue(int value){
        if(isFull()){
            cout << "Queue Overflow" << endl;
            return;
        }
        if(isEmpty()){
            front = 0;
        }

        arr[++rear] = value;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return 0;
        }

        int temp = arr[front];
        front++;
        if(isEmpty()){
            front = rear = -1;
        }

        return temp;
    }

    void display(){
        if(isEmpty()){
            cout << "Empty Queue" << endl;
            return;
        }

        int curr = front;
        while(curr <= rear){
            cout << arr[curr] << " - ";
            curr++;
        }
        cout << endl;
    }
};



int main(){
    LinkedList list;

    list.prepend(20);
    list.prepend(50);
    list.append(10);
    list.append(40);
    list.display();

    list.deleteValue(10);
    list.display();

    Stack stack;

    stack.push(10);
    stack.push(100);
    stack.push(1000);
    stack.push(10000);

    stack.display();

    cout << "Peek: "<< stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.display();

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;
    
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();


    return 0;
}