#include <iostream>
using namespace std;

class Node {
public:
    string name; 
    int score;   
    Node* next;

    Node() : name(""), score(0), next(nullptr) {}
    Node(string n, int s) : name(n), score(s), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;

  
    int getMaxScore() {
        int maxScore = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->score > maxScore) {
                maxScore = current->score;
            }
            current = current->next;
        }
        return maxScore;
    }

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(string name, int score) {
        Node* newNode = new Node(name, score);

        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " (" << current->score << ")->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }


    void radixSort() {
        int maxScore = getMaxScore();
        for (int exp = 1; maxScore / exp > 0; exp *= 10) {
            Node* outputHead = nullptr;
            Node* outputTail = nullptr;

            Node* current = head;
            while (current != nullptr) {
                Node* nextNode = current->next;
                current->next = nullptr;  

                
                if (outputHead == nullptr || (current->score / exp) % 10 < (outputHead->score / exp) % 10) {
                    current->next = outputHead;
                    outputHead = current;
                    if (outputTail == nullptr) {
                        outputTail = current;
                    }
                } else {
                    Node* traverse = outputHead;
                    while (traverse->next != nullptr && (traverse->next->score / exp) % 10 <= (current->score / exp) % 10) {
                        traverse = traverse->next;
                    }
                    current->next = traverse->next;
                    traverse->next = current;
                    if (current->next == nullptr) {
                        outputTail = current;
                    }
                }
                current = nextNode;
            }

        
            head = outputHead;
        }
    }
};

int main() {
    LinkedList studentList;
    studentList.insertAtEnd("Alice", 85);
    studentList.insertAtEnd("Bob", 42);
    studentList.insertAtEnd("Charlie", 95);
    studentList.insertAtEnd("David", 63);
    studentList.insertAtEnd("Eva", 77);

    cout << "Original list:" << endl;
    studentList.print();

    studentList.radixSort();

    cout << "Sorted list:" << endl;
    studentList.print();

    return 0;
}
