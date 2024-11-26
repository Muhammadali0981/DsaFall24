#ifndef BINARYST_H
#define BINARYST_H

#include <iostream>
#include "record.h"

class Node {
    Record record;
    Node* left;
    Node* right;

public:
    Node(Record r) : record(r), left(nullptr), right(nullptr) {}

    Record getRecord() const {return record;}
    void setRecord(Record r) { record = r;}

    Node* getLeft() const {return left;}
    void setLeft(Node* l) {left = l;}

    Node* getRight() const {return right; }
    void setRight(Node* r) {right = r; }

};

class BST {
    Node* root;

public:
    BST() : root(nullptr) {}

    Node* insertHelper(Record r, Node* curr) {
        if (curr == nullptr) {
            return new Node(r);
        }

        if (curr->getRecord().getId() > r.getId()) {
            curr->setLeft(insertHelper(r, curr->getLeft()));
        }
        else if (curr->getRecord().getId() < r.getId()) {
            curr->setRight(insertHelper(r, curr->getRight()));
        }
        else {
            std::cout << "No duplicates allowed." << std::endl;
        }
        return curr;
    }

    // Public function to insert a record into the tree
    void insert(Record r) {
        root = insertHelper(r, root);
    }

    // Helper function to search for a record by id
    Node* searchHelper(int id, Node* curr) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (curr->getRecord().getId() == id) {
            return curr;
        }

        if (curr->getRecord().getId() > id) {
            return searchHelper(id, curr->getLeft());
        }
        else {
            return searchHelper(id, curr->getRight());
        }
    }

    // Public function to search for a record by id
    Node* search(int id) {
        Node* result = searchHelper(id, root);
        if (result != nullptr) {
            std::cout << "Id: " << result->getRecord().getId() << " ";
            std::cout << "Name: " << result->getRecord().getName() << " ";
            std::cout << "Age: " << result->getRecord().getAge() << std::endl;
        } else {
            std::cout << "Node doesn't exist" << std::endl;
        }
        return result;
    }

    // Helper function to find the minimum value node in the right subtree
    Node* minValueNode(Node* curr) {
        while (curr && curr->getLeft() != nullptr) {
            curr = curr->getLeft();
        }
        return curr;
    }

    // Helper function to delete a record by id
    Node* deleteHelper(int id, Node* curr) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (curr->getRecord().getId() > id) {
            curr->setLeft(deleteHelper(id, curr->getLeft()));
        }
        else if (curr->getRecord().getId() < id) {
            curr->setRight(deleteHelper(id, curr->getRight()));
        }
        else {
            // Node to be deleted found
            if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
                delete curr;
                return nullptr;
            }
            else if (curr->getLeft() == nullptr) {
                Node* temp = curr->getRight();
                delete curr;
                return temp;
            }
            else if (curr->getRight() == nullptr) {
                Node* temp = curr->getLeft();
                delete curr;
                return temp;
            }
            else {
                Node* temp = minValueNode(curr->getRight());
                curr->setRecord(temp->getRecord());
                curr->setRight(deleteHelper(temp->getRecord().getId(), curr->getRight()));
            }
        }
        return curr;
    }

    // Public function to delete a record by id
    void deleteNode(int id) {
        if (search(id)) {
            root = deleteHelper(id, root);
            std::cout << "Node deleted!" << std::endl;
        } else {
            std::cout << "Node doesn't exist in tree!" << std::endl;
        }
    }

    // Helper function to perform in-order traversal of the tree
    void inOrder(Node* curr) {
        if (curr) {
            inOrder(curr->getLeft());
            std::cout << curr->getRecord().getAge() << " " << curr->getRecord().getId() << " " << curr->getRecord().getName() << std::endl;
            inOrder(curr->getRight());
        }
    }

    // Public function to print the entire tree in-order
    void printTree() {
        inOrder(root);
    }
};

#endif