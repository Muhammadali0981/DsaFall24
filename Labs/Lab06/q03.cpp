#include <iostream>
using namespace std;


class TicketQueue {
    int front, rear;
    int capacity;
    int* queue;

public:
    TicketQueue(int size = 10) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }


    bool isFull() {
        return rear == capacity - 1;
    }

    
    bool isEmpty() {
        return front == -1 || front > rear;
    }


    void enqueue(int passenger) {
        if (isFull()) {
            cout << "Queue is full. Cannot add passenger " << passenger << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        queue[rear] = passenger;
        cout << "Passenger " << passenger << " added to the queue." << endl;
    }

   
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Passenger " << queue[front] << " has purchased a ticket and is removed from the queue." << endl;
        front++;
    }

    
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};


struct Node {
    int passenger;
    Node* next;

    Node(int p): passenger(p), next(nullptr) {}
};


class LinkedListQueue {
    Node* front;
    Node* rear;

public:
    LinkedListQueue(): front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    
    void enqueue(int passenger) {
        Node* newNode = new Node(passenger);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Passenger " << passenger << " added to the queue." << endl;
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << "Passenger " << front->passenger << " has purchased a ticket and is removed from the queue." << endl;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        Node* current = front;
        while (current) {
            cout << current->passenger << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    // Part (a) - Linear Queue using Array
    cout << "Linear Queue (Array) Implementation:" << endl;
    TicketQueue tq;

    // Add 10 passengers to the linear queue
    for (int i = 1; i <= 10; i++) {
        tq.enqueue(i);
    }
    tq.displayQueue();

    // Remove 5 passengers from the queue
    for (int i = 0; i < 5; i++) {
        tq.dequeue();
    }
    tq.displayQueue();

    // Try adding 5 more passengers (this will fail as it's a fixed-size queue)
    for (int i = 11; i <= 15; i++) {
        tq.enqueue(i);
    }
    tq.displayQueue();

    cout << "\nLinked List Queue Implementation:" << endl;

    // Part (c) - Linked List Queue
    LinkedListQueue llq;

    // Add 10 passengers to the linked list queue
    for (int i = 1; i <= 10; i++) {
        llq.enqueue(i);
    }
    llq.displayQueue();

    // Remove 5 passengers from the queue
    for (int i = 0; i < 5; i++) {
        llq.dequeue();
    }
    llq.displayQueue();

    // Try adding 5 more passengers (this will work as the queue is dynamic)
    for (int i = 11; i <= 15; i++) {
        llq.enqueue(i);
    }
    llq.displayQueue();

    return 0;
}
