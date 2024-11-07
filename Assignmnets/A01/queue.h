#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int size;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity];
        }
        delete[] data;
        data = newData;
        front = 0;
        rear = size - 1;
    }

public:
    Queue() : capacity(10), front(0), rear(-1), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& element) {
        if (size == capacity) {
            resize();
        }
        rear = (rear + 1) % capacity;
        data[rear] = element;
        ++size;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        T element = data[front];
        front = (front + 1) % capacity;
        --size;
        return element;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return data[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No pending tickets." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << data[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

#endif
