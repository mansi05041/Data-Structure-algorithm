// Stack_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Apply Stack using array


#include <iostream>
using namespace std;
constexpr auto Size = 20; //define macro;

// user defined functions 
void push(int arr[], int &top);
void pop(int arr[], int &top);
bool isempty(int &top);
bool isfull(int &top);
void display(int arr[], int &top);
int peek(int arr[], int &top);

// main - function 
int main()
{   
	int option, top;
	top = -1; //stack is empty initially
	do {
		cout << "Stack Implementation using Array" << endl;
		cout << "1.push" << endl;
		cout << "2.pop" << endl;
		cout << "3.peek" << endl;
		cout << "4.display" << endl;
		cout << "5.exit" << endl;
		cout << "Enter the choice : ";
		cin >> option;
		int arr[Size];
		switch (option) {
		case 1:cout << "Implementing push operation" << endl;
			   push(arr, top);
			   break;
		case 2:cout << "Implementing pop operation" << endl;
			   pop(arr, top);
			   break;
		case 3:cout << "Implementing the peek operation" << endl;
			   cout << peek(arr, top) << " is the top element of stack" << endl;
			   break;
		case 4:cout << "Display the stack" << endl;
			   display(arr, top);
			   break;
		case 5:cout << "The program terminate here !!!";
			   break;
		default:cout << "Wrong input!!!" << endl;
			    cout << "Try again" << endl;
		}
		cout << "\n**********************************************************************\n";
	} while (option!=5); // continue till option!=5

	return 0;
}

// function to push an element
void push(int arr[], int &top) {
	if (isfull(top)) {
		cout << "Stack is overflow" << endl;
		cout << "Can't perform the Push operation" << endl;
	}
	else {
		top++; // Incrementing the top value
		cout << "Enter the element to be push : ";
		cin >> arr[top];
		cout << arr[top] << " is push into stack at position : " << top << endl;
	}
}

// function to pop an element
void pop(int arr[],int &top){
	if (isempty(top)) {
		cout << "Stack is underflow" << endl;
		cout << "Can't perform the function of Pop operation" << endl;
    }
	else {
		int del = arr[top];
		top--; // decrementing the top value
		cout << "The element pop from the stack is : " << del << endl;
    }
}

// function to check the stack is empty or not
bool isempty(int &top) {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

// fuction to check the stack is full or not 
bool isfull(int &top) {
	if (top == Size - 1) {
		return true;
	}
	else {
		return false;
	}
}

// function for peek operation : to get an element at the top of stack
int peek(int arr[], int &top) {
	if (isempty(top)) {
		cout << "Stack is underflow" << endl;
		cout << "Can't perform the operation of peek" << endl;
	}
	else {
		return(arr[top]);
	}
}

// function to display
void display(int arr[], int &top) {
	if (isempty(top)) {
		cout << "Stack is underflow / empty" << endl;
		cout << "No element to display" << endl;
	}
	else {
		for (int i = top; i > -1; i--) {
			cout << arr[i];
			cout << endl;
		}
	}
}
