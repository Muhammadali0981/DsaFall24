#ifndef AVL_TABLE_H
#define AVL_TABLE_H

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "record.h"
using namespace std;



class AVLNode {
public:
    Record data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(const Record& record) : data(record), left(nullptr), right(nullptr), height(1) {}
};

class AVLTable {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(AVLNode* node) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* insertRecursive(AVLNode* node, const Record& record) {
        if (node == nullptr) {
            return new AVLNode(record);
        }

        if (record.id < node->data.id) {
            node->left = insertRecursive(node->left, record);
        } else if (record.id > node->data.id) {
            node->right = insertRecursive(node->right, record);
        } else {
            return node; // Duplicate keys not allowed
        }

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && record.id < node->left->data.id) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && record.id > node->right->data.id) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && record.id > node->left->data.id) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && record.id < node->right->data.id) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* searchRecursive(AVLNode* node, int id) {
        if (node == nullptr || node->data.id == id) {
            return node;
        }

        if (id < node->data.id) {
            return searchRecursive(node->left, id);
        }

        return searchRecursive(node->right, id);
    }

    AVLNode* findMinNode(AVLNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    AVLNode* deleteRecursive(AVLNode* node, int id) {
        if (node == nullptr) return nullptr;

        if (id < node->data.id) {
            node->left = deleteRecursive(node->left, id);
        } else if (id > node->data.id) {
            node->right = deleteRecursive(node->right, id);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                AVLNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                AVLNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            AVLNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data.id);
        }

        if (node == nullptr) return nullptr;

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // Left Right Case
        if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void clearRecursive(AVLNode* node) {
        if (node) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

public:
    AVLTable() : root(nullptr) {}

    ~AVLTable() {
        clearRecursive(root);
    }

    void insert(const Record& record) {
        root = insertRecursive(root, record);
    }

    Record* search(int id) {
        AVLNode* result = searchRecursive(root, id);
        return result ? &(result->data) : nullptr;
    }

    void remove(int id) {
        root = deleteRecursive(root, id);
    }
};

#endif 
