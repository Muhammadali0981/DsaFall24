#include <iostream>
#include <string>
using namespace std;

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray {
private
    T* data;         
    int capacity;  
    int size;      

    
    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    
    DynamicArray() : capacity(2), size(0) {
        data = new T[capacity];
    }

    
    ~DynamicArray() {
        delete[] data;
    }

    // Add an element to the array
    void push_back(const T& element) {
        if (size == capacity) {
            resize();
        }
        data[size++] = element;
    }

   
    T& operator[](int index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    
    int getSize(){
        return size;
    }

    
    void display(){
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

#endif
