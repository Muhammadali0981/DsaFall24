#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

struct Book {
    int id;
    string name;
    string author;
};

class HashTable {
private:
    vector<list<Book>> table;

    int hashFunction(int bookID) {
        return bookID % 10;
    }

public:
    HashTable() : table(10) {}

    void insert(int bookID, const string& name, const string& author) {
        int index = hashFunction(bookID);
        table[index].push_back({bookID, name, author});
        cout << "Inserted Book ID " << bookID << " at index " << index << endl;
    }

    void search(int bookID) {
        int index = hashFunction(bookID);
        for (const auto& book : table[index]) {
            if (book.id == bookID) {
                cout << "Found Book ID " << bookID << ": " << book.name << " by " << book.author << endl;
                return;
            }
        }
        cout << "Book ID " << bookID << " not found." << endl;
    }

    void remove(int bookID) {
        int index = hashFunction(bookID);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->id == bookID) {
                cout << "Deleted Book ID " << bookID << endl;
                table[index].erase(it);
                return;
            }
        }
        cout << "Book ID " << bookID << " not found for deletion." << endl;
    }

    void display() {
        for (int i = 0; i < table.size(); ++i) {
            cout << "Index " << i << ": ";
            for (const auto& book : table[i]) {
                cout << "[ID: " << book.id << ", Name: " << book.name << ", Author: " << book.author << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable catalog;

    
    catalog.insert(101, "Book1", "AuthorA");
    catalog.insert(102, "Book2", "AuthorA");
    catalog.insert(103, "Book3", "AuthorA");
    catalog.insert(201, "Book4", "AuthorB");
    catalog.insert(202, "Book5", "AuthorB");
    catalog.insert(301, "Book6", "AuthorC");
    catalog.insert(302, "Book7", "AuthorC");
    catalog.insert(303, "Book8", "AuthorC");
    catalog.insert(304, "Book9", "AuthorC");

    cout << "\nInitial Hash Table:\n";
    catalog.display();

    
    catalog.search(101); 
    catalog.search(304); 
    catalog.search(999); 

    
    catalog.remove(101);
    catalog.remove(304);

    cout << "\nHash Table after Deletions:\n";
    catalog.display();

    return 0;
}