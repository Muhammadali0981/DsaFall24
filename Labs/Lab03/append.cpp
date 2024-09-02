#include <iostream>

using namespace std;


class Node
{
private:
    int data;
    Node* next;

public:
    Node():data(0),next(nullptr){}
    Node(const int a):data(a), next(nullptr){}

    friend class linkedlist;
};

class linkedlist
{
private:
    Node* head;
public:
    linkedlist(): head(nullptr){}
    linkedlist(Node* h):head(h){}

    void Append(int data){
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


    void print() {
        

        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

};


int main(){
    Node* myNode = new Node(4);
    Node* myNode2 = new Node(5);
    linkedlist* list = new linkedlist(myNode);
    list->print();

}