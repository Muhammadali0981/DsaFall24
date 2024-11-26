#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "record.h"

class Node {
    Record record;
    Node* left;
    Node* right;
    int height;

public:
    Node(Record r) {
        record = r;
        left = right = nullptr;
        height = 1;
    }

    friend class AVL;
};

class AVL {
    Node* root;

    int height_(Node* n) { return n ? n->height : 0; }
    int getBalance(Node* n) { return n ? height_(n->left) - height_(n->right) : 0; }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height_(y->left), height_(y->right)) + 1;
        x->height = std::max(height_(x->left), height_(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height_(x->left), height_(x->right)) + 1;
        y->height = std::max(height_(y->left), height_(y->right)) + 1;

        return y;
    }

    Node* insert(Node* curr, Record r) {
        if (curr == nullptr) {
            return new Node(r);
        }
        if (r.getId() < curr->record.getId()) {
            curr->left = insert(curr->left, r);
        } else if (r.getId() > curr->record.getId()) {
            curr->right = insert(curr->right, r);
        } else {
            return curr; // Duplicate IDs are not allowed
        }

        curr->height = std::max(height_(curr->left), height_(curr->right)) + 1;

        int balance = getBalance(curr);

        // Left Left Case
        if (balance > 1 && r.getId() < curr->left->record.getId()) {
            return rotateRight(curr);
        }

        // Right Right Case
        if (balance < -1 && r.getId() > curr->right->record.getId()) {
            return rotateLeft(curr);
        }

        // Left Right Case
        if (balance > 1 && r.getId() > curr->left->record.getId()) {
            curr->left = rotateLeft(curr->left);
            return rotateRight(curr);
        }

        // Right Left Case
        if (balance < -1 && r.getId() < curr->right->record.getId()) {
            curr->right = rotateRight(curr->right);
            return rotateLeft(curr);
        }

        return curr;
    }

    Node* minValueNode(Node* curr) {
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    Node* deleteNode(Node* curr, int id) {
        if (!curr) return nullptr;

        if (id < curr->record.getId()) {
            curr->left = deleteNode(curr->left, id);
        } else if (id > curr->record.getId()) {
            curr->right = deleteNode(curr->right, id);
        } else {
            if (!curr->left || !curr->right) {
                Node* temp = curr->left ? curr->left : curr->right;
                if (!temp) {
                    temp = curr;
                    curr = nullptr;
                } else {
                    *curr = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(curr->right);
                curr->record = temp->record;
                curr->right = deleteNode(curr->right, temp->record.getId());
            }
        }

        if (!curr) return nullptr;

        curr->height = std::max(height_(curr->left), height_(curr->right)) + 1;

        int balance = getBalance(curr);

        // Left Left Case
        if (balance > 1 && getBalance(curr->left) >= 0) {
            return rotateRight(curr);
        }

        // Left Right Case
        if (balance > 1 && getBalance(curr->left) < 0) {
            curr->left = rotateLeft(curr->left);
            return rotateRight(curr);
        }

        // Right Right Case
        if (balance < -1 && getBalance(curr->right) <= 0) {
            return rotateLeft(curr);
        }

        // Right Left Case
        if (balance < -1 && getBalance(curr->right) > 0) {
            curr->right = rotateRight(curr->right);
            return rotateLeft(curr);
        }

        return curr;
    }

    Node* search(Node* curr, int id) {
        if (!curr || curr->record.getId() == id) {
            return curr;
        }
        if (id < curr->record.getId()) {
            return search(curr->left, id);
        }
        return search(curr->right, id);
    }

    void inOrder(Node* curr) {
    if (curr) {
        inOrder(curr->left);  
        std::cout << curr->record.getAge() << " " << curr->record.getId() << " " << curr->record.getName() << std::endl;  // Print the current node's record
        inOrder(curr->right);  
    }
}

public:
    AVL() : root(nullptr) {}

    void insert(Record r) {
        root = insert(root, r);
    }

    void deleteNode(int id) {
        root = deleteNode(root, id);
    }

    bool search(int id) {
        return search(root, id) != nullptr;
    }

    void inOrderTraversal() {
        inOrder(root);
        std::cout << std::endl;
    }
};

#endif // AVL_H
