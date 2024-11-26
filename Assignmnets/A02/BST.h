#include <iostream>
#include <string>

using namespace std;

#ifndef BST_H
#define BST_H

class Bst{

private:
    struct Node
    {
        int ID;
        string Name;
        int Age;  
        Node* left;
        Node* right;

        Node(int i, string n, int a): ID(i), Name(n), Age(a), left(nullptr), right(nullptr) {}

    }* root;

    Node* insert(int i, string n, int a, Node* root){

        if(!root) return new Node(i, n, a);
        if(root->ID > i) root->left = insert(i, n , a, root->left);
        else root->right = insert(i, n, a, root->right);
    
        return root;

    }
    
   
    Node* search(int i, Node* root) {

        if (!root) {
            cout << "ID " << i << " not found in the tree" << endl;
            return nullptr;
        }
        if (root->ID == i) return root;

        if (i < root->ID) return search(i, root->left);
        else return search(i, root->right);
    }

    void InOrder(Node* root){
        if(!root) return;

        InOrder(root->left);
        cout << "Id: " << root->ID << " Name: " << root->Name << " Age: " << root->Age << endl;
        InOrder(root->right);
        
    }


public:
    Bst() : root(nullptr) {}

    void insert(int i, string n, int a) {
        root = insert(i, n, a, root);
    }

    Node* search(int i) {
        return search(i, root);
    }

    void display(){
        InOrder(root);
    }
};

#endif