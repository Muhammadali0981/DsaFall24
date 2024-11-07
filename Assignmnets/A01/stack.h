#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int top;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i <= top; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Stack() : capacity(10), top(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& element) {
        if (top == capacity - 1) {
            resize();
        }
        data[++top] = element;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return data[top--];
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return data[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No logs to display." << endl;
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << data[i] << endl;
        }
    }
};

#endif
