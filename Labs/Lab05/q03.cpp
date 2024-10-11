#include <iostream>


using namespace std;

#include <iostream>

using namespace std;


class Node
{
private:
    int data;
    Node* next;

public:
    Node():data(0),next(NULL){}
    Node(const int a):data(a), next(NULL){}

    friend class linkedlist;
};

class linkedlist
{

public:
    Node* head;
    linkedlist(): head(nullptr){}
    linkedlist(Node* h):head(h){}

    void insertAtEnd(int data){
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }
        Node* current = this->head;

        while(current->next != nullptr){
            current = current->next;
        }

        current->next = newNode;

    }

    void insertAtStart(int data){
        Node* newNode = new Node(data);
        
        if(head == nullptr) head = newNode;
        else{
            newNode->next = head;
            head = newNode;
        }    
    }

    
    
    void reverse(Node* current, Node* prev){

        
        if(!current){
            head = prev;
            return;
        }
        
        reverse(current->next, current);
        current->next = prev;
    }

    void print() {
        
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

};

int main()
{
    linkedlist list;
    
    list.insertAtStart(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    cout << "after inserting and appending" << endl;
    list.print();
    list.reverse(list.head, nullptr);
    list.print();
    return 0;
}
