#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "BinaryST.h"   
#include "AVL.h"   
#include "BTree.h" 
#include "record.h"

using namespace std;
using namespace chrono;


vector<Record> generateDummyData(int size) {
    vector<Record> data;
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        int id = rand() % 100000;  // Random ID
        string name = "Name" + to_string(i);  // Sample Name
        int age = rand() % 100;  // Random age
        data.push_back(Record(id, name, age));
    }
    return data;
}


template <typename T>
long long measureInsert(T& tree, const vector<Record>& data) {
    auto start = high_resolution_clock::now();
    for (const auto& r : data) {
        tree.insert(r); 
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}

// Function to measure Search operation time for a given tree
template <typename T>
long long measureSearch(T& tree, const vector<Record>& data, int numSearches) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numSearches; ++i) {
        int randomIdx = rand() % data.size();
        tree.search(data[randomIdx].getId());  
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}

// Function to measure Delete operation time for a given tree
template <typename T>
long long measureDelete(T& tree, const vector<Record>& data) {
    auto start = high_resolution_clock::now();
    for (const auto& r : data) {
        tree.deleteKey(r.getId());  
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}


int main() {
    // Define the sizes of the datasets to test
    vector<int> sizes = {1000, 10000, 50000};
    int numSearches = 20;  // Number of search queries to run

    // Run performance tests for each tree type
    for (int size : sizes) {
        cout << "Testing with dataset size: " << size << endl;
        vector<Record> data = generateDummyData(size);

        // BST test
        BST bst;
        cout << "BST Insert time: " << measureInsert(bst, data) << " microseconds" << endl;
        cout << "BST Search time: " << measureSearch(bst, data, numSearches) << " microseconds" << endl;
        cout << "BST Delete time: " << measureDelete(bst, data) << " microseconds" << endl;
        cout << "BST Update time: " << measureUpdate(bst, data) << " microseconds" << endl;

        // AVL Tree test
        AVL avl;
        cout << "AVL Insert time: " << measureInsert(avl, data) << " microseconds" << endl;
        cout << "AVL Search time: " << measureSearch(avl, data, numSearches) << " microseconds" << endl;
        cout << "AVL Delete time: " << measureDelete(avl, data) << " microseconds" << endl;
        cout << "AVL Update time: " << measureUpdate(avl, data) << " microseconds" << endl;

        // B-Tree test
        BTree btree(3);  // Assuming minimum degree of 3 for the BTree
        cout << "BTree Insert time: " << measureInsert(btree, data) << " microseconds" << endl;
        cout << "BTree Search time: " << measureSearch(btree, data, numSearches) << " microseconds" << endl;
        cout << "BTree Delete time: " << measureDelete(btree, data) << " microseconds" << endl;
        cout << "BTree Update time: " << measureUpdate(btree, data) << " microseconds" << endl;

        cout << "------------------------------------" << endl;
    }

    return 0;
}
