// Queue_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Implement Queue using array
/*Name : Mansi joshi
* Roll no :102/2019
* Course :Bsc Physical Science
*/

#include <iostream>
#define size 20
using namespace std;

// user-defined functions
void enqueue(int ele);
void dequeue();
void display();
bool isempty();
bool isfull();
int peek();

// global variables
int front, rear = -1; // intially queue is empty
int queue[size]; 

// main-function
int main()
{
    // variable declaration
    int choice = 0;
    int ele;

    // menu-driven
    do
    {
        cout << "\nQueue functions";
        cout << "\n1.Insertion of element into queue ";
        cout << "\n2.Remove the element from queue";
        cout << "\n3.Get the element in front of queue";
        cout << "\n4.Display the queue";
        cout << "\n5.Exit the program";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:cout << "\nEnter the element to be inserted in queue : ";
               cin >> ele;
               enqueue(ele);
               break;
        case 2:dequeue();
               break;
        case 3:ele = peek();
               cout << "\nFront element of queue : " << ele;
               break;
        case 4:display();
               break;
        case 5:cout << "\nProgram terminated here!!";
               break;
        default:cout << "\nWrong option, choose from 1-5";
        }
        cout << "\n*******************************************************************\n";
    } while (choice!=5);
    
    return 0;
}

// function to add element in queue
void enqueue(int ele) {
    if (isfull()) {
        // full queue
        cout << "\nOverflow , can't insert element";
    }
    else {
        if (isempty()) {
            // empty queue
            front = rear = 0;
        }
        else {
            // more than 1 element in queue
            rear += 1; // increment the rear (insert at end)
        }
        queue[rear]=ele;
        cout << "\nElement " << ele << " inserted at " << rear;
    }
}

// function to remove element from queue
void dequeue() {
    if (isempty()) {
        cout << "\nQueue is underflow";
    }
    else if (front == rear) {
        // only one element there
        cout << "\nElement " << queue[front] << " removed";
        front = rear = -1;
    }
    else {
        // there are more than 1 element
        cout << "\nElement " << queue[front] << " removed";
        front += 1; // increment of front value ( deletion from front )
    }
}

// function to display the queue
void display() {
    if (isempty()) {
        cout << "\nEmpty queue";
    }
    else {
        cout << "\nElements in queue :\n";
        for (int i = front; i < rear+1; i++) {
            cout << queue[i] << " ";
        }
    }
}

// function to check queue is empty
bool isempty() {
    if (front == -1) {
        return true;
    }
    else {
        return false;
    }
}

// function to check queue is full
bool isfull() {
    if (rear == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

// function to get top value of queue
int peek() {
    if (isempty()) {
        cout << "Queue is Empty";
        return -1;
    }
    else {
        return queue[front];
    }
}