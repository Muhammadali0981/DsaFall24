#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "record.h"

using namespace std;

class BTreeNode {
public:
    vector<Record> keys;       // Records within the node
    vector<BTreeNode*> children; // Child pointers
    bool isLeaf;               // Whether the node is a leaf

    BTreeNode(bool leaf) : isLeaf(leaf) {}

    // Function to traverse the B-Tree
    void traverse();

    // Insert a new record into a non-full node
    void insertNonFull(const Record& record, int t);

    // Split a child node
    void splitChild(int i, int t);

    // Function to search for a record in the subtree rooted at this node
    BTreeNode* search(int id);

    // Function to delete a record from the subtree rooted at this node
    void deleteRecord(int id, int t);

    // Utility functions for deletion
    int findKey(int id);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx, int t);
    Record getPredecessor(int idx);
    Record getSuccessor(int idx);
    void fill(int idx, int t);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx, int t);
};


class BTree {
private:
    BTreeNode* root;
    int t;           // Minimum degree (defines the range of keys in nodes)

public:
    BTree(int degree) : root(nullptr), t(degree) {}

    // Function to traverse the tree
    void traverse() {
        if (root) root->traverse();
    }

    // Function to search for a record
    BTreeNode* search(int id) {
        return root ? root->search(id) : nullptr;
    }

    // Function to insert a new record
    void insert(const Record& record);

    // Function to delete a record
    void deleteRecord(int id);
};

// Function to traverse the B-Tree
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        // If this is not a leaf, traverse the subtree before printing the record
        if (!isLeaf)
            children[i]->traverse();
        cout << "ID: " << keys[i].getId() 
             << ", Name: " << keys[i].getName() 
             << ", Age: " << keys[i].getAge() << endl;
    }

    // Print the subtree rooted at the last child
    if (!isLeaf)
        children[i]->traverse();
}

// Function to search a record by ID in the subtree rooted at this node
BTreeNode* BTreeNode::search(int id) {
    int i = 0;
    while (i < keys.size() && id > keys[i].getId())
        i++;

    if (i < keys.size() && keys[i].getId() == id)
        return this;

    if (isLeaf)
        return nullptr;

    return children[i]->search(id);
}

// Utility function to find the index of the first key >= id
int BTreeNode::findKey(int id) {
    int idx = 0;
    while (idx < keys.size() && keys[idx].getId() < id)
        idx++;
    return idx;
}

// Function to delete a record
void BTreeNode::deleteRecord(int id, int t) {
    int idx = findKey(id);

    if (idx < keys.size() && keys[idx].getId() == id) {
        if (isLeaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx, t);
    } else {
        if (isLeaf) {
            cout << "Record with ID " << id << " is not found in the tree.\n";
            return;
        }

        bool flag = (idx == keys.size());
        if (children[idx]->keys.size() < t)
            fill(idx, t);

        if (flag && idx > keys.size())
            children[idx - 1]->deleteRecord(id, t);
        else
            children[idx]->deleteRecord(id, t);
    }
}

// Function to remove a record from a leaf node
void BTreeNode::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

// Function to remove a record from a non-leaf node
void BTreeNode::removeFromNonLeaf(int idx, int t) {
    Record record = keys[idx];

    if (children[idx]->keys.size() >= t) {
        Record pred = getPredecessor(idx);
        keys[idx] = pred;
        children[idx]->deleteRecord(pred.getId(), t);
    } else if (children[idx + 1]->keys.size() >= t) {
        Record succ = getSuccessor(idx);
        keys[idx] = succ;
        children[idx + 1]->deleteRecord(succ.getId(), t);
    } else {
        merge(idx, t);
        children[idx]->deleteRecord(record.getId(), t);
    }
}

// Function to get the predecessor of a record
Record BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->isLeaf)
        cur = cur->children.back();
    return cur->keys.back();
}

// Function to get the successor of a record
Record BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->isLeaf)
        cur = cur->children[0];
    return cur->keys[0];
}

// Function to fill a child node
void BTreeNode::fill(int idx, int t) {
    if (idx != 0 && children[idx - 1]->keys.size() >= t)
        borrowFromPrev(idx);
    else if (idx != keys.size() && children[idx + 1]->keys.size() >= t)
        borrowFromNext(idx);
    else {
        if (idx != keys.size())
            merge(idx, t);
        else
            merge(idx - 1, t);
    }
}

// Function to borrow a key from the previous sibling
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];

    child->keys.insert(child->keys.begin(), keys[idx - 1]);
    keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();

    if (!child->isLeaf)
        child->children.insert(child->children.begin(), sibling->children.back());
    sibling->children.pop_back();
}

// Function to borrow a key from the next sibling
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys.push_back(keys[idx]);
    keys[idx] = sibling->keys[0];
    sibling->keys.erase(sibling->keys.begin());

    if (!child->isLeaf)
        child->children.push_back(sibling->children[0]);
    sibling->children.erase(sibling->children.begin());
}

// Function to merge two children
void BTreeNode::merge(int idx, int t) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys.push_back(keys[idx]);
    for (int i = 0; i < sibling->keys.size(); i++)
        child->keys.push_back(sibling->keys[i]);

    if (!child->isLeaf) {
        for (int i = 0; i <= sibling->children.size(); i++)
            child->children.push_back(sibling->children[i]);
    }

    keys.erase(keys.begin() + idx);
    children.erase(children.begin() + idx + 1);
    delete sibling;
}

// Function to insert a record into the B-Tree
void BTree::insert(const Record& record) {
    if (!root) {
        root = new BTreeNode(true);
        root->keys.push_back(record);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, t);
            root = newRoot;
        }
        root->insertNonFull(record, t);
    }
}

// Function to delete a record from the B-Tree
void BTree::deleteRecord(int id) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }

    root->deleteRecord(id, t);

    if (root->keys.empty()) {
        BTreeNode* oldRoot = root;
        root = root->isLeaf ? nullptr : root->children[0];
        delete oldRoot;
    }
}

#endif // BTREE_H
