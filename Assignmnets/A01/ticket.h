#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;
#ifndef TICKET_H
#define TICKET_H

struct Ticket{
    int ticketID;
    string customerName;
    int priority;
    string description;
    time_t creationTime;
    string status;
    time_t* closeTime;


    Ticket(int id, string n, int p, string d,  string s):ticketID(id), customerName(n), priority(p), 
    description(d), creationTime(time(nullptr)), status(s), closeTime(nullptr){}
};

class Node
{

public:
    Ticket data;
    Node* next;
    Node(Ticket data) : data(data), next(nullptr) {}
    
    friend class ticketlist;
};

class ticketlist
{

public:
    Node* head;

    ticketlist(): head(nullptr){}
    ticketlist(Node* h):head(h){}

    void insertAtEnd(Ticket data){
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

    void insertAtStart(Ticket data){
        Node* newNode = new Node(data);
        
        if(head == nullptr) head = newNode;
        else{
            newNode->next = head;
            head = newNode;
        }    
    }

    void insertAfter(int value, Ticket data){
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            cout << "placeholder not found" << endl;
            return;
        }

        else{
            Node* current = head;
            while(current->data.ticketID != value){
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
                
        }

    }

    void insertBefore(int value, Ticket data){
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }

        else{
            Node* current = head;
            while(current->next->data.ticketID != value){
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
        if(head->data.ticketID == value) deleteFromHead();
        while(current->next->data.ticketID != value){
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = current->next->next;  
        delete temp;

    }

    Ticket* findbyid(int id){
        
        Node* current = head;
        while (current && current->data.ticketID != id)
            current = current->next;

        return current ? &current->data : nullptr;
    }

    
    void sort_by_priority() {
        if (!head || !head->next) {
            cout << "List is empty or has only one node" << endl;
            return;
        }

        bool sorted = false;

        while (!sorted) {
            sorted = true;  
            Node* current = head;
            Node* prev = nullptr;

            while (current->next) {  
                if (current->data.priority > current->next->data.priority) {
                    
                    sorted = false;  

                    Node* temp = current->next;
                    current->next = temp->next;
                    temp->next = current;

                    if (prev == nullptr) {
                        head = temp; 
                    } else {
                        prev->next = temp;  
                    }
                
                    prev = temp;
                } else {

                    prev = current;
                    current = current->next;
                }
            }
        }
    }
   
    void sort_by_time(Node* head) {
        Node* current = head, *sorted = nullptr;

        while (head) {
            Node* current = head;
            head = head->next;

            if (!sorted || current->data.creationTime > sorted->data.creationTime) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* sorted_curr = sorted;
                while (sorted_curr->next && current->data.creationTime <= sorted_curr->data.creationTime)
                    sorted_curr = sorted_curr->next;

                current->next = sorted_curr->next;
                sorted_curr->next = current;
            }
        }

    
    }

    void sort_by_name() {
        if (head == nullptr) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }

        for (Node* sorted = head; sorted != nullptr; sorted = sorted->next) {
            Node* min = sorted;
            for (Node* curr = sorted->next; curr != nullptr; curr = curr->next) {
                if (curr->data.customerName < min->data.customerName) {
                    min = curr;
                }
            }
            if (min != sorted) {
                swap(sorted->data, min->data);
            }
        }
    }

};

#endif