/*
    Name:Muhammad Ali
    Date:08/09/24
    Desc: doubly linked list with sorting and duplicate removal
*/

#include <iostream>

using namespace std;

class Node {

    private:
    int data;
    Node* next;
    Node* prev;

    friend class DoublyLinkedList;

    public:
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    private:
    Node* head;

    public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtFront(int value) {
        Node* newNode = new Node(value);

         if(head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while(current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
        
    }

    void insertBefore(int value, int key) {
        Node* new_node = new Node(value);
        if (head == nullptr) { 
            return;
        }

        Node* current = head;
        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current == head) {
            new_node->next = head;
            new_node->prev = nullptr;
            head->prev = new_node;
            head = new_node;
            return;
        }

        new_node->next = current;
        new_node->prev = current->prev;

        if (current->prev != nullptr) {
            current->prev->next = new_node;
        }

        current->prev = new_node;
    }

   void insertAfter(int value, int key) {
        if (head == nullptr) {
            return;  
        }

        Node* new_node = new Node(value);

        Node* current = head;
        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Key " << key << " not found in the list.\n";
            delete new_node;
            return;  
        }

        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != nullptr) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }

    void deleteHead() {
        Node *toDelete = head;

        if(head == nullptr) {
            return;
        }

        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        delete toDelete;
    }

    void deleteEnd() {
        if (head == nullptr) { return; }

        Node* current = head;
        while(current->next->next != nullptr) { current = current->next; }

        Node* toDelete = current->next;
        current->next = nullptr;

        delete toDelete;
    }

    void deleteAtValue(int value) {
        Node* current = head;

        if (head == nullptr) {
            std::cout << "List is empty. No deletion performed.\n";
            return;
        }

        while(current != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Value " << value << " not found.\n";
            return;
        }

        Node* toDelete = current->next;
        current->next = current->next->next;
        if(current->next != nullptr) 
            current->next->prev = current;

        delete toDelete;
    }

    void printList() {
        Node* current = head;
        while(current != nullptr) {
            cout<< current->data<<" <=> ";
            current = current->next;
        }
        cout<< "null" << std::endl;
    }

    
    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            return; 
        }

        bool swapped;
        Node* current;
        Node* last = nullptr;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;

                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

    
    void removeDuplicates() {
        if (head == nullptr) {
            return; 
        }

        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* toDelete = current->next;
                current->next = current->next->next;
                if (current->next != nullptr) {
                    current->next->prev = current;
                }
                delete toDelete;
            } else {
                current = current->next;
            }
        }
    }
};

int main() {
    DoublyLinkedList doubly_link_list;

  
    doubly_link_list.insertAtEnd(4);
    doubly_link_list.insertAtEnd(1);
    doubly_link_list.insertAtEnd(3);
    doubly_link_list.insertAtEnd(2);
    doubly_link_list.insertAtEnd(4); 

    cout << "Original List: " << endl;
    doubly_link_list.printList();

    
    doubly_link_list.bubbleSort();
    cout << "Sorted List: " << endl;
    doubly_link_list.printList();

    
    doubly_link_list.removeDuplicates();
    cout << "List after removing duplicates: " << endl;
    doubly_link_list.printList();

    return 0;
}
