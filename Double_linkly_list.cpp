// Double_linkly_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Double linkly list implementation 
/* Name : Mansi joshi
*  Roll no : 2019/102
*  Course : Bsc Physical Science
*  Subject : Analysis of Algorithm
*/

#include <iostream>;
using namespace std;

// node class declaration
class node {
public:
    int data;
    node* prev;
    node* next;

    node(int a) {
        this->data = a;
        this->prev = this->next = NULL;
    }

};

// d_list class declaration
class d_list {
public:
    node* start;
    
    d_list() {
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

// function to insert element at the beginning
void d_list::insert_beg(int value) {
    node* temp = new node(value); // creating a new node
    if (start == NULL) {
        start = temp;
    }
    else {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }              
    cout << value << " is inserted at the beginnig" << endl;
}

// function to insert element at the end
void d_list::insert_end(int value) {
    node* temp = new node(value); // creating a new node
    if (start == NULL) {
        start = temp;
    }
    else {
        node* ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
    cout << value << " is inserted at the end" << endl;
}

// function to insert element in the between the list
void d_list::insert_bw(int value, int pos) {
    node* temp = new node(value); // creating a new node
    if (pos == 0) {
        insert_beg(value); // insertion at beginning
    }
    else {
        node* ptr = start; // by looping get the node at (pos-1)
        while (pos > 1) {
            ptr = ptr->next;
            --pos; // decrement of position
        }
        if (ptr->next == NULL) {
            insert_end(value); // insertion at the end
        }
        else {
            temp->prev = ptr;
            temp->next = ptr->next; // insertion node between (pos-1) and pos
            ptr->next = temp;
        }
    }
    cout << value << " is inserted at the position " << pos << endl;
}

// function to delete element at the beginning
void d_list::delete_beg() {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        cout << "Deleted element " << start->data << endl;
        node* temp = start;
        start = start->next; // set next node as fist node
        start->prev = NULL; // not pointing the previous node
        delete(temp); // delete the node
    }
}

// function to delete element at the end
void d_list::delete_end() {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        node* ptr = start;
        while (ptr->next->next != NULL) {
            ptr = ptr->next; // transversal to second last node
        }
        node* temp = ptr;
        temp = temp->next; // temp is now last node
        ptr->next = NULL;
        cout << temp->data << " is deleted\n";
        delete(temp);
    }
}

// function to delete element in the between the list
void d_list::delete_bw(int pos) {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        node* temp, * ptr;
        if (pos == 0) {
            // deletion at beginning
            delete_beg();
        }
        else {
            ptr = start;
            while (pos > 1) {
                --pos;
                ptr = ptr->next;
            }
            if (ptr->next == NULL) {
                //deletion at end
                delete_end();
            }
            else {
                temp = ptr->next;
                cout << "Element Deleted : " << temp->data << endl;
                ptr->next = temp->next;
                temp = temp->next;
                temp->prev = ptr;
                free(ptr); // free the node at pos
            }
        }
    }
}

// function to display the list
void d_list::display_list() {
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        int ch;
        cout << "\nChoose the Transversal :::\n";
        cout << "1.Forward Transversal\n";
        cout << "2.Backward Transversal\n";
        cout << "Enter the choice :: ";
        cin >> ch;
        if (ch == 1) {
            //forward transversal
            node* forw = start;
            cout << "NULL" << "->";
            while (forw != NULL) {
                cout << forw->data<<"->";
                forw = forw->next;
            }
            cout << "NULL\n";
        }
        else if (ch == 2) {
            //backward transversal
            node* back = start;
            cout << "NULL" << "->";
            while (back->next != NULL) {
                back = back->next;
            }
            while (back!= start) {
                cout << back->data << "->";
                back = back->prev;
            }
            cout << back->data << "->";
            cout << "NULL\n";
        }
        else {
            cout << "Enter the wrong option\n";
        }
    }
}

// main function
int main()
{
    // declaration of variable
    int ch, data, pos;
    d_list l;
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
        cout << "\n*************************************\n";
    } while (ch != 8);
    return 0;
}

