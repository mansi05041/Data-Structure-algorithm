// queue_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// implement queue data structure using linked list
/*Name : mansi joshi
* Roll no : 102/2019
* Course : Bsc Physical science
* Subject : Analysis of algorithm
*/

#include <iostream>
using namespace std;

// node class declaration
class node {
public:
    int data;
    node* next;

    // constructor
    node(int x) {
        data = x;
        next = NULL;
    }
};

// queue class declaration
class queue {
public:
    node* front;
    node* rear;
    queue() {
        front = rear = NULL;
    }
    void enqueue(int ele);
    void dequeue();
    void display();
    void peek();
    bool isempty();
};

// function to insert an element into queue
void queue::enqueue(int ele) {
    node* newnode = new node(ele); // creation of new node
    if (isempty()) {
        // queue is empty
        front = rear = newnode;
    }
    else {
        // queue is not empty
        rear->next = newnode;
        rear = newnode;
    }
    cout << "\nElement " << ele << " is inserted at end of queue";
    cout << "\n***************************************\n";
}

// function to remove an element from queue
void queue::dequeue() {
    node* temp;
    int data;
    if (isempty()) {
        cout << "Queue is empty";
    }
    else if(front->next==NULL){
        // only one element in queue
        temp = front;
        data = front->data;
        delete(temp);
        front = rear = NULL;
        cout << "\nThe element delete from linked list : " << data;
    }
    else {
        temp = front;
        data = front->data;
        front = front->next;
        delete(temp);
        cout << "\nThe element delete from linked list : " << data;
    }
}

// function to display the queue
void queue::display() {
    node* temp = front;
    if (isempty()) {
        cout << "\nQueue is empty";
    }
    else {
        cout << "\nElements present in queue : \n";
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
}

// function to get the front element of queue
void queue::peek() {
    if (isempty()) {
        cout << "queue is empty";
    }
    else {
        cout << "\nElement at front of queue : " << front->data;
    }
}

// function to check the queue is empty or not
bool queue::isempty() {
    if (front == NULL && rear == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// main function
int main()
{
    // variable declaration 
    int choice = 0;
    int ele;
    queue q;
    do
    {
        cout << "\nImplementation of queue using linked list ";
        cout << "\n1.Insetion of element in queue";
        cout << "\n2.Remove element from queue";
        cout << "\n3.Get the front value of queue";
        cout << "\n4.Display the queue";
        cout << "\n5.Exit";
        cout << "\nEnter the choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:cout << "Enter the element to be insert in queue : ";
               cin >> ele;
               q.enqueue(ele);
               break;
        case 2:q.dequeue();
               break;
        case 3:q.peek();
               break;
        case 4:q.display();
               break;
        case 5:cout << "\nThe program terminate here!!";
               break;
        default:cout << "Wrong option!, try options (1-5)";
        }
        cout << "\n*****************************************************************\n";
    } while (choice!=5);
    return 0;
}







