#include <iostream>
#include <vector>
using namespace std;

class DoubleHashing {
private:
    vector<int> table;
    int tableSize;

    int primaryHash(int accountID) {
        return accountID % tableSize;
    }

    int secondaryHash(int accountID) {
        return 7 - (accountID % 7);
    }

public:
    DoubleHashing(int size) : tableSize(size), table(size, -1) {}

    void insert(int accountID) {
        int index = primaryHash(accountID);
        int step = secondaryHash(accountID);

        while (table[index] != -1) {
            index = (index + step) % tableSize; // Double hashing
        }

        table[index] = accountID;
        cout << "Inserted Account ID " << accountID << " at index " << index << endl;
    }

    void search(int accountID) {
        int index = primaryHash(accountID);
        int step = secondaryHash(accountID);
        int start = index;

        do {
            if (table[index] == accountID) {
                cout << "Found Account ID " << accountID << " at index " << index << endl;
                return;
            }
            index = (index + step) % tableSize;
        } while (table[index] != -1 && index != start);

        cout << "Account ID " << accountID << " not found." << endl;
    }

    void remove(int accountID) {
        int index = primaryHash(accountID);
        int step = secondaryHash(accountID);
        int start = index;

        do {
            if (table[index] == accountID) {
                cout << "Deleted Account ID " << accountID << " from index " << index << endl;
                table[index] = -1; // Mark as deleted
                return;
            }
            index = (index + step) % tableSize;
        } while (table[index] != -1 && index != start);

        cout << "Account ID " << accountID << " not found for deletion." << endl;
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
    DoubleHashing bankSystem(11);

   
    bankSystem.insert(101);
    bankSystem.insert(111);
    bankSystem.insert(121);
    bankSystem.insert(131);
    bankSystem.insert(141);
    bankSystem.insert(151);

    cout << "\nInitial Hash Table:\n";
    bankSystem.display();

    
    bankSystem.search(111); 
    bankSystem.search(141); 
    bankSystem.search(161); 


    bankSystem.remove(111);
    bankSystem.remove(131);

    
    bankSystem.insert(161);
    bankSystem.insert(171);

    cout << "\nHash Table after Deletions and Insertions:\n";
    bankSystem.display();

    return 0;
}
