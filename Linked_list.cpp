// Linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Linked list implementation using C++


#include <iostream>
using namespace std;
 
// class declaration of Node
class Node {
   
// data members
public:
    int data;
    Node *addr;

// Constructor
    Node(int a) {
        this->addr = NULL;
        this->data = a;
    }
};

// class declaration of linked list
class Linked_list {

public:
    Node *start; // contains address of first node

    Linked_list() {
        start = NULL;
    }
    // functions to be performed
    void insert_beg(int value);
    void insert_end(int value);
    void insert_bw(int value, int pos);
    void delete_beg();
    void delete_end();
    void delete_bw(int pos);
    void display_list();
};

// method to insert node at beginning
void Linked_list::insert_beg(int value) {
    Node *temp = new Node(value); // creating a new node
    temp->addr = start;
    start = temp;
}

// method to insert node at end
void Linked_list::insert_end(int value) {
    Node* temp = new Node(value); // creating a new node
    if (start==NULL) {
        start = temp; // if it is first node
    }
    else {
        Node *check = start; // by looping reaching the end of linked list
        while (check->addr != NULL) {
            check = check->addr;
        }
        check->addr = temp; // store the temp address into last node adress part
    }
}

// method to insert node in between the linked list
void Linked_list::insert_bw(int value, int pos) {
    Node* temp = new Node(value); // creating a new node
    if (pos == 0) {
        temp->addr = start; // insertion at beginning
        start = temp;
    }
    else {
        Node* check = start; // by looping get the node at (pos-1)
        while (pos > 1) {
            check = check->addr;
            --pos; // decrement of position
        }
        temp->addr = check->addr; // insertion node between (pos-1) and pos
        check->addr = temp;
    }
}

// method to delete node at beginning
void Linked_list::delete_beg() {
    if (start==NULL) {
        cout << "List is empty" << endl;
    }
    else {
        cout << "Deleted element" << start->data << endl;
        Node *temp = start;
        start = start->addr; // set next node as fist node
        delete(temp); // delete the node
    }
}

// method to delete node in end
void Linked_list::delete_end() {
    if (start==NULL) {
        cout << "List is empty" << endl;
    }
    else {
        Node *temp = start;
        while (temp->addr->addr != NULL) {
            temp = temp->addr; // getting the second last node
        }
        cout << "Element deleted : " << temp->addr->data << endl;
        delete(temp->addr); // delete last node
        temp->addr = NULL; // setting last node's address as NULL
    }
}

// method to delete node in between the linked list
void Linked_list::delete_bw(int pos) {
    if (start==NULL) {
        cout << "List is empty" << endl;
    }
    else {
        Node *temp, *ptr;
        if (pos == 0) {
            // deletion at beginning
            cout << "Element deleted : " << start->data << endl;
            ptr = start;
            start = start->addr;
            delete(ptr);
        }
        else {
            temp = ptr = start;
            while (pos > 0) {
                --pos;
                temp = ptr;
                ptr = ptr->addr;
            }
            cout << "Element Deleted : " << ptr->data << endl;
            temp->addr = ptr->addr;
            free(ptr); // free the node at pos
        }
    }
}

// method to display the linked list
void Linked_list::display_list() {
    if (start==NULL) {
        cout << "List is empty" << endl;
    }
    else {
        Node *temp = start;
        cout << "Linked List" << endl;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->addr;
        }
        cout << "NULL" << endl;
    }
}

// main method
int main()
{
    // declaration of variable
    int ch, data, pos;
    Linked_list l;
    do
    {
        //menu-driven
        cout << "Implementation of linked list" << endl;
        cout << "1. Insertion at beginning" << endl;
        cout << "2. Insertion at end" << endl;
        cout << "3. Insertion in between the linked list" << endl;
        cout << "4. Deletion at beginning" << endl;
        cout << "5. Deletion at end" << endl;
        cout << "6. Deletion in between the linked list" << endl;
        cout << "7. Display the linked list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter the choice :: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter the element to be insert at beginning : ";
            cin >> data;
            l.insert_beg(data);
            break;
        case 2:
            cout << "Enter the element to be insert at end : ";
            cin >> data;
            l.insert_end(data);
            break;
        case 3:
            cout << "Enter the element to be insert : ";
            cin >> data;
            cout << "Enter the position at where insertion to be performed : ";
            cin >> pos;
            l.insert_bw(data, pos);
            break;
        case 4:
            l.delete_beg();
            break;
        case 5:
            l.delete_end();
            break;
        case 6:
            cout << "Enter the position at which deletion to be performed : ";
            cin >> pos;
            l.delete_bw(pos);
            break;
        case 7:
            l.display_list();
            break;
        case 8:
            cout << "Program terminates here !!!" << endl;
            exit(0);
        default:
            cout << "Wrong Choice input !!!" << endl;
        }
        cout < "\n****************************************************************\n";
    } while (ch!=8);
    return 0;
}

