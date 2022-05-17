// Binary_search_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Creation and transversal of Binary Search Tree

#include <iostream>
using namespace std;
#define size 10

// global variables
class node {

public:
    // data members
    int data;
    node *left, *right;
    node(int value) {
        data = value;
        left = right = NULL;
    }
};

class tree {
public:
    // data members
    node* root;
    tree() {
        root = NULL;
    }
    bool isempty();
    void insertNode(int value);
    void transversal();
    void inorder(node* temp);
    void preorder(node* temp);
    void postorder(node* temp);
};

tree t;

// function to check if the tree is empty or not
bool tree::isempty() {
    if (root == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// funnction to insert node into the tree
void tree::insertNode(int value) {
    node* new_node = new node(value);
    if (isempty()) {
        // tree is empty
        root = new_node;
        cout << "\nValue inserted as root node";
    }
    else {
        node* temp = root;
        while (temp != NULL) {
            if (new_node->data == temp->data) {
                cout << "\nValue already exist, Insert another value";
                return;
            }
            else if ((new_node->data < temp->data) && (temp->left == NULL)) {
                temp->left = new_node;
                cout << "\nValue Inserted at left of " << temp->data;
                break;
            }
            else if (new_node->data < temp->data) {
                temp = temp->left;
            }
            else if ((new_node->data > temp->data) && (temp->right == NULL)) {
                temp->right = new_node;
                cout << "\nValue Inserted at right of " << temp->data;
                break;
            }
            else {
                temp = temp->right;
            }
        }
    }
}

// function for transversal
void tree::transversal() {
    int ch;
    node* temp = root;
    cout << "\nChoose the Transversal option ";
    cout << "\n1.Preorder";
    cout << "\n2.Inorder";
    cout << "\n3.Postorder";
    cout << "\nEnter the choice ::: ";
    cin >> ch;
    switch (ch) {
    case 1: cout << "\nPreoder transversal\n";
        preorder(temp);
        break;
    case 2: cout << "\nInorder transversal\n";
        inorder(temp);
        break;
    case 3: cout << "\nPostorder transversal\n";
        postorder(temp);
        break;
    default: cout << "Wrong option";
    }
}

// function for preorder
void tree::preorder(node* temp) {
    if (temp == NULL) {
        return;
    }
    else {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

// function for inorder
void tree::inorder(node* temp) {
    if (temp == NULL) {
        return;
    }
    else {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// function for postorder
void tree::postorder(node* temp) {
    if (temp == NULL) {
        return;
    }
    else {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}
// main-function
int main()
{ 
    int ch, val;
    do {
        cout << "\nWhat operation do you want to perform ?";
        cout << "\n1.Insertion of Node into BST";
        cout << "\n2.Transversal of tree";
        cout << "\n3.Exit program";
        cout << "\nEnter the choice ::";
        cin >> ch;
        switch (ch)
        {
        case 1: // insertion
            cout << "\nEnter the value of node to insert into BST ::";
            cin >> val;
            t.insertNode(val);
            cout << "\n";
            break;
        case 2: // transversal
            t.transversal();
            break;
        case 3:
            cout << "\nProgram terminates!!";
            break;
        default:
            cout << "\nWrong option try again!!";
        }
    } while (ch != 3);
}


