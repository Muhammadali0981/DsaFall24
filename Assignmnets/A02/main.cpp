#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "bst.h"
#include "avl.h"
#include "btree.h"
#include "record.h"

using namespace std;

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}


vector<Record> generateDummyData(int size) {
    vector<Record> data;
    
    for (int i = 0; i < size; ++i) {
        Record rec;
        rec.id = i + 1;  // Unique IDs
        rec.name = "Person_" + to_string(i);
        rec.age = generateRandomNumber(18, 80);
        data.push_back(rec);
    }

    return data;
}


template<typename TreeType>
void measurePerformance(TreeType& table, const vector<Record>& data) {
    clock_t start, end;

    
    start = clock();
    for (const auto& record : data) {
        table.insert(record);
    }
    end = clock();
    double insertTime = double(end - start) / CLOCKS_PER_SEC * 1000; // milliseconds

   
    vector<int> searchIds;
    for (int i = 0; i < 20; ++i) {
        searchIds.push_back(generateRandomNumber(1, data.size()));
    }

    
    start = clock();
    int successfulSearches = 0;
    for (int id : searchIds) {
        if (table.search(id) != nullptr) {
            successfulSearches++;
        }
    }
    end = clock();
    double searchTime = double(end - start) / CLOCKS_PER_SEC * 1000; // milliseconds


    start = clock();
    for (int id : searchIds) {
        table.remove(id);
    }
    end = clock();
    double deleteTime = double(end - start) / CLOCKS_PER_SEC * 1000; // milliseconds

    // Print results
    cout << "Insert Time: " << insertTime << " \n";
    cout << "Search Time: " << searchTime << " \n";
    cout << "Delete Time: " << deleteTime << " \n";
    cout << "Successful Searches: " << successfulSearches << "/20\n\n";
}

int main() {
    // Seed random number generator
    srand(time(nullptr));

    // Dataset sizes to test
    int datasetSizes[] = {1000, 10000, 50000};
    
    for (int size : datasetSizes) {
        cout << "Dataset Size: " << size << " records\n";
        cout << "----------------------------\n";

        
        vector<Record> data = generateDummyData(size);

        
        cout << "Binary Search Tree (BST) Performance:\n";
        BSTTable bstTable;
        measurePerformance(bstTable, data);

        cout << "AVL Tree Performance:\n";
        AVLTable avlTable;
        measurePerformance(avlTable, data);

        cout << "B-Tree Performance:\n";
        BTreeTable bTreeTable;
        measurePerformance(bTreeTable, data);
    }

    return 0;
}