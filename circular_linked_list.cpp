// circular_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Implementation of circular linked list

#include <iostream>
using namespace std;

// node class declaration
class Node {
public:
    int data;
    Node* next;
    // constructor
    Node(int a) {
        data = a;
        this->next = NULL;
    }
};

// class declaration of circular linked list
class c_list {

public:
    Node* start; // contains address of first node
    Node* end; // contains address of last node

    c_list() {
        start = NULL;
        end = NULL;
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
void c_list::insert_beg(int value) {
    Node* temp = new Node(value); // creating a new node
    if (start == NULL || end == NULL) {
        // empty list
        start = end = temp;
    }
    else {
        temp->next = start;
        start = temp;
        end->next = start; // last node now point to first one
    }
    cout << value << " insert at beginning";
}

// method to insert node at end
void c_list::insert_end(int value) {
    Node* temp = new Node(value); // creating a new node
    if (start == NULL || end == NULL) {
        start = end = temp; // if it is first node
    }
    else {
        temp->next = start;
        end->next = temp;
        end = temp;
    }
    cout << value << " insert at end";
}

// method to insert node in between the linked list
void c_list::insert_bw(int value, int pos) {
    Node* temp = new Node(value); // creating a new node
    int t = pos;
    if (pos == 0) {
        insert_beg(value); // calling the function insert at beginning 
    }
    else {
        Node* check = start; // by looping get the node at (pos-1)
        while (pos > 1) {
            check = check->next;
            --pos; // decrement of position
        }
        if (check->next == start) {
            insert_end(value); // calling the function insert at end
        }
        else {
            temp->next = check->next; // insertion node between (pos-1) and pos
            check->next = temp;
        }
    }
    cout <<"\n" << value << " insert at position " << t;
}

// method to delete node at beginning
void c_list::delete_beg() {
    if (start == NULL) {
        cout << "List is empty" << "\n";
    }
    else {
        cout << "Deleted element" << start->data << "\n";
        Node* temp = start;
        start = start->next; // set next node as fist node
        end->next = start; // last node points first one
        delete(temp); // delete the node
    }
}

// method to delete node in end
void c_list::delete_end() {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        Node* temp = start;
        while (temp->next != end) {
            temp = temp->next; // getting the second last node
        }
        cout << "Element deleted : " << temp->next->data << endl;
        Node* dele = end;
        delete(dele); // delete last node
        temp->next = start; // setting last node's address to first node
        end = temp;
    }
}

// method to delete node in between the linked list
void c_list::delete_bw(int pos) {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        Node* temp, * ptr;
        if (pos == 0) {
            // deletion at beginning
            delete_beg();
        }
        else {
            temp = ptr = start;
            while (pos > 0) {
                --pos;
                temp = ptr;
                ptr = ptr->next;
            }
            if (ptr->next == NULL) {
                // deletion at end
                delete_end();
            }
            else {
                cout << "Element Deleted : " << ptr->data << endl;
                temp->next = ptr->next;
                free(ptr); // free the node at pos
            }
        }
    }
}

// method to display the linked list
void c_list::display_list() {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        Node* temp = start;
        cout << "Linked List" << endl;
        while (temp->next!=start) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
    }
}

// main method
int main()
{
    // declaration of variable
    int ch, data, pos;
    c_list l;
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
        cout << "\n****************************************************************\n";
    } while (ch != 8);
    return 0;
}
