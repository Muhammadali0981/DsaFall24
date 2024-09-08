/*
    Name:Muhammad Ali
    Date:08/09/24
    Desc: linked list odd first then even 
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

    void deleteFromHead(){
        if(head != nullptr){
            Node* temp = head;
            head = temp->next;
            delete temp;
            temp = NULL;
        }

        else cout << "list is empty" << endl;
    }

    void deleteNode(int value){
        Node* current = head;
        if(head->data == value) deleteFromHead();
        else {
            while(current->next != nullptr && current->next->data != value){
                current = current->next;
            }
            if (current->next != nullptr) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    void separateOddEven() {
        Node* current = head;
        while(current->next) {
            if (current->next->data%2 == 0) {
                Node* temp = current->next;
                current->next = current->next->next;
                temp->next = head;
                head = temp;
                continue;
            }
            current = current->next;    
        }
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
    list.insertAtEnd(16);
    list.insertAtEnd(17);
    list.insertAtEnd(160);
    list.insertAtEnd(11);
    list.insertAtEnd(9);
    
    cout << "After inserting and appending" << endl;
    list.print();
    
    cout << "Segregating odd and even:" << endl;
    list.separateOddEven();
    list.print();

    return 0;
}
