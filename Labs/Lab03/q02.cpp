/*
    Name:Muhammad Ali
    Date:08/09/24
    Desc: revrse
*/
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
private:
    Node* head;
public:
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

    void insertAfter(int value, int data){
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            cout << "placeholder not found" << endl;
            return;
        }

        else{
            Node* current = head;
            while(current->data != value){
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
                
        }

    }

    void insertBefore(int value, int data){
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }

        else{
            Node* current = head;
            while(current->next->data != value){
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
            
    
        }


    }

    void deleteFromHead(){
        if(head != nullptr){
            Node* temp = head;
            head = temp->next;
            delete temp;
            temp = NULL;
        }

        else cout << "list is empty" << endl;

    }

    void deleteLastNode(){

        Node* current = this->head;
        
        while(current->next->next != nullptr){
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;


    }

    void deleteNode(int value){
        
        Node* current = head;
        if(head->data == value) deleteFromHead();
        while(current->next->data != value){
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = current->next->next;  
        delete temp;

    }

    void reverse(){
        Node* current = this->head;
        Node* perv = nullptr;
        Node* next = nullptr;

        while (current != nullptr){
            next = current->next;
            current->next = perv;
            perv = current;
            current = next;

        }

        this->head = perv;
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

int main(){
    linkedlist list;
    list.insertAtStart(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    cout << "after inserting and appending" << endl;
    list.print();
    list.insertAfter(6, 1);
    cout << "inserted 1 after 6" << endl;
    list.print();
    list.insertBefore(6,2);
    cout << "inserted 2 before 6" << endl;
    list.print();
    list.deleteFromHead();
    cout << "deleted from head" << endl;
    list.print();
    list.deleteLastNode();
    cout << "deleted last node" << endl;
    list.print();
    list.deleteNode(7);
    cout << "deleted last node with value 7" << endl;
    list.print();
    cout << "before reversing:" << endl;
    list.print();
    cout << "after reversing:" << endl;
    list.reverse();
    list.print();
}