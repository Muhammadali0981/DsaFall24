#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <chrono>
#include "record.h"


class BSTNode {
public:
    Record data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const Record& record) : data(record), left(nullptr), right(nullptr) {}
};

class BSTTable {
private:
    BSTNode* root;

    BSTNode* insertRecursive(BSTNode* node, const Record& record) {
        if (node == nullptr) {
            return new BSTNode(record);
        }

        if (record.id < node->data.id) {
            node->left = insertRecursive(node->left, record);
        } else if (record.id > node->data.id) {
            node->right = insertRecursive(node->right, record);
        }

        return node;
    }

    BSTNode* searchRecursive(BSTNode* node, int id) {
        if (node == nullptr || node->data.id == id) {
            return node;
        }

        if (id < node->data.id) {
            return searchRecursive(node->left, id);
        }

        return searchRecursive(node->right, id);
    }

    BSTNode* findMinNode(BSTNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    BSTNode* deleteRecursive(BSTNode* node, int id) {
        if (node == nullptr) return nullptr;

        if (id < node->data.id) {
            node->left = deleteRecursive(node->left, id);
        } else if (id > node->data.id) {
            node->right = deleteRecursive(node->right, id);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            BSTNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data.id);
        }
        return node;
    }

    void clearRecursive(BSTNode* node) {
        if (node) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

public:
    BSTTable() : root(nullptr) {}

    ~BSTTable() {
        clearRecursive(root);
    }

    void insert(const Record& record) {
        root = insertRecursive(root, record);
    }

    Record* search(int id) {
        BSTNode* result = searchRecursive(root, id);
        return result ? &(result->data) : nullptr;
    }

    void remove(int id) {
        root = deleteRecursive(root, id);
    }
};

#endif // BST_TABLE_H
