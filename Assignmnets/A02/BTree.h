#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <chrono>
#include "record.h"
const int ORDER = 4; 



class BTreeNode {
public:
    bool leaf;
    std::vector<Record> records;
    std::vector<BTreeNode*> children;

    BTreeNode(bool is_leaf = true) : leaf(is_leaf) {}
};

class BTreeTable {
private:
    BTreeNode* root;

    void splitChild(BTreeNode* parent, int index) {
        BTreeNode* child = parent->children[index];
        BTreeNode* newChild = new BTreeNode(child->leaf);

        
        for (int j = 0; j < (ORDER - 1) / 2; j++) {
            newChild->records.push_back(child->records[ORDER / 2]);
            child->records.erase(child->records.begin() + ORDER / 2);
        }

        
        if (!child->leaf) {
            for (int j = 0; j < ORDER / 2; j++) {
                newChild->children.push_back(child->children[ORDER / 2]);
                child->children.erase(child->children.begin() + ORDER / 2);
            }
        }

        parent->records.insert(parent->records.begin() + index, child->records[0]);
        child->records.erase(child->records.begin());
        parent->children.insert(parent->children.begin() + index + 1, newChild);
    }

    void insertNonFull(BTreeNode* node, const Record& record) {
        int i = node->records.size() - 1;

        if (node->leaf) {
            node->records.push_back(Record());
            while (i >= 0 && record.id < node->records[i].id) {
                node->records[i + 1] = node->records[i];
                i--;
            }
            node->records[i + 1] = record;
        } else {
            while (i >= 0 && record.id < node->records[i].id) {
                i--;
            }
            i++;

            if (node->children[i]->records.size() == 2 * ORDER - 1) {
                splitChild(node, i);
                if (record.id > node->records[i].id) {
                    i++;
                }
            }
            insertNonFull(node->children[i], record);
        }
    }

    Record* searchRecursive(BTreeNode* node, int id) {
        int i = 0;
        while (i < node->records.size() && id > node->records[i].id) {
            i++;
        }

        if (i < node->records.size() && id == node->records[i].id) {
            return &(node->records[i]);
        }

        if (node->leaf) {
            return nullptr;
        }

        return searchRecursive(node->children[i], id);
    }

    void removeRecursive(BTreeNode* node, int id) {
        
        for (auto it = node->records.begin(); it != node->records.end(); ++it) {
            if (it->id == id) {
                node->records.erase(it);
                return;
            }
        }

        if (!node->leaf) {
            for (auto& child : node->children) {
                removeRecursive(child, id);
            }
        }
    }

    void clearRecursive(BTreeNode* node) {
        if (node) {
            for (auto& child : node->children) {
                clearRecursive(child);
            }
            delete node;
        }
    }

public:
    BTreeTable() : root(new BTreeNode()) {}

    ~BTreeTable() {
        clearRecursive(root);
    }

    void insert(const Record& record) {
        if (root->records.size() == 2 * ORDER - 1) {
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->children.push_back(root);
            splitChild(newRoot, 0);
            root = newRoot;
        }
        insertNonFull(root, record);
    }

    Record* search(int id) {
        return searchRecursive(root, id);
    }

    void remove(int id) {
        removeRecursive(root, id);
    }
};

#endif 
