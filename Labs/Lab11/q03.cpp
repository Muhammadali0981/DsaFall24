#include <iostream>
#include <vector>
using namespace std;

class DynamicHashTable {
private:
    vector<int> table;
    int tableSize;
    int itemCount;
    double loadFactorThreshold;

    int hashFunction(int studentID) {
        return studentID % tableSize;
    }

    void rehash() {
        cout << "\nRehashing...\n";
        int oldSize = tableSize;
        tableSize *= 2;
        vector<int> newTable(tableSize, -1);

        for (int i = 0; i < oldSize; ++i) {
            if (table[i] != -1) {
                int index = table[i] % tableSize;
                while (newTable[index] != -1) {
                    index = (index + 1) % tableSize; 
                }
                newTable[index] = table[i];
            }
        }

        table = move(newTable);
        cout << "Rehashing complete. New table size: " << tableSize << endl;
    }

public:
    DynamicHashTable(int size, double loadFactor) : tableSize(size), itemCount(0), loadFactorThreshold(loadFactor), table(size, -1) {}

    void insert(int studentID) {
        if ((double)itemCount / tableSize >= loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(studentID);
        while (table[index] != -1) {
            index = (index + 1) % tableSize; 
        }

        table[index] = studentID;
        itemCount++;
        cout << "Inserted Student ID " << studentID << " at index " << index << endl;
    }

    void search(int studentID) {
        int index = hashFunction(studentID);
        int start = index;

        do {
            if (table[index] == studentID) {
                cout << "Found Student ID " << studentID << " at index " << index << endl;
                return;
            }
            index = (index + 1) % tableSize;
        } while (index != start);

        cout << "Student ID " << studentID << " not found." << endl;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < tableSize; ++i) {
            if (table[i] == -1)
                cout << "Index " << i << ": Empty" << endl;
            else
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    DynamicHashTable universityPortal(7, 0.75);

    
    universityPortal.insert(12);
    universityPortal.insert(22);
    universityPortal.insert(32);
    universityPortal.insert(42);
    universityPortal.insert(52);
    universityPortal.insert(62);

    cout << "\nInitial Hash Table:\n";
    universityPortal.display();

    
    universityPortal.search(22);
    universityPortal.search(42); 
    universityPortal.search(72); 

   
    universityPortal.insert(72);
    universityPortal.insert(82);

    cout << "\nHash Table after Exceeding Load Factor:\n";
    universityPortal.display();

    return 0;
}
