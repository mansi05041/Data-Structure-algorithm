// stack_using_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// implementing stack using linked list



#include <iostream>
using namespace std;

// user defined functions
void push_stack(int value);
void pop_stack();
void peek();
bool isempty();
void display();

// node class
class node {
public:

	// data members
	int data;
	node* next;

	// constructor
	node(int ele) {
		data = ele;
		this->next = NULL;
	}

};

// global variable 
node* top;

// main function 
int main()
{
	// declare variables
	int option, value;
	
	// menu driven 
	do
	{
		cout << "\nStack operations" << endl;
		cout << "1. Push operation" << endl;
		cout << "2. Pop operation" << endl;
		cout << "3. Peek operation " << endl;
		cout << "4. Display the stack" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter the choice  : ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter the data to be push into stack : ";
			cin >> value;
			push_stack(value);
			break;
		case 2:
			pop_stack();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			cout << "The program terminates here !!!" << endl;
			exit(0);
		default:
			cout << "wrong input !!!" << endl;
		}
	} while (option!=5); // looping until it get exit option

	return 0;
}

// function to push an element in stack
void push_stack(int value) {
	node* newnode = new node(value); // new node created
	if (isempty()) {
		// adding first node
		top = newnode;
	}
	else {
		// there are more than one node in stack
		newnode->next = top;
		top = newnode;
	}
	cout << "The element " << newnode->data << " is push into stack " << endl;
}

// function to pop an element from stack
void pop_stack() {
	if (isempty()) {
		cout << "No pop operation perform" << endl;
		cout << "Stack is underflow" << endl;
	}
	else {
		node* temp; // creation of a new node
		temp = top;
		top = temp->next;
		cout << "The element " << temp->data << " is pop from stack" << endl;
		delete(temp); // delete the top node
	}
}

// function to get top element 
void peek() {
	if (isempty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		node* temp; // creation of a new node
		temp = top;
		cout << "The top element of stack  : " << temp->data << endl;
	}
}

// function to display the linked list 
void display() {
	if (isempty()) {
		cout << "\nStack is Empty";
	}
	else {
		node* temp = top;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

// function to check is stack empty
bool isempty() {
	if (top == NULL) {
		return true;
	}
	else {
		return false;
	}
}
