#include <iostream>
#include <vector>
using namespace std;

class FitnessClub {
private:
    vector<int> table;
    int tableSize;

    int hashFunction(int memberID) {
        return memberID % tableSize;
    }

public:
    FitnessClub(int size) : tableSize(size), table(size, -1) {}

    void insert(int memberID) {
        int index = hashFunction(memberID);

        while (table[index] != -1) {
            index = (index + 1) % tableSize; // Linear probing
        }

        table[index] = memberID;
        cout << "Inserted Member ID " << memberID << " at index " << index << endl;
    }

    void search(int memberID) {
        int index = hashFunction(memberID);
        int start = index;

        do {
            if (table[index] == memberID) {
                cout << "Found Member ID " << memberID << " at index " << index << endl;
                return;
            }
            index = (index + 1) % tableSize;
        } while (index != start);

        cout << "Member ID " << memberID << " not found." << endl;
    }

    void remove(int memberID) {
        int index = hashFunction(memberID);
        int start = index;

        do {
            if (table[index] == memberID) {
                cout << "Deleted Member ID " << memberID << endl;
                table[index] = -1; // Mark as deleted
                return;
            }
            index = (index + 1) % tableSize;
        } while (index != start);

        cout << "Member ID " << memberID << " not found for deletion." << endl;
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
    FitnessClub club(7);

    
    for (int id = 10; id <= 60; id += 10)
        club.insert(id);

    cout << "\nInitial Hash Table:\n";
    club.display();

    
    club.search(30); 
    club.search(50); 
    club.search(70); 

   
    club.remove(20);
    club.remove(40);

   
    club.insert(70);
    club.insert(80);

    cout << "\nHash Table after Insertions and Deletions:\n";
    club.display();

    return 0;
}
