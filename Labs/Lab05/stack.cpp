#include <iostream>

using namespace std;

template <typename T>
class Stack_array {
    T* data;
    unsigned length, capacity;

    void shrink() {
        T* new_data = new T[length];
        for (int i = 0; i < length; ++i)
            new_data[i] = data[i];
        delete data;
        data = new_data;
        capacity = length;
    }

    void grow() {
        capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i < length; ++i)
            new_data[i] = data[i];
        delete data;
        data = new_data;
    }
public:
    Stack_array(): data(new T[1]), length(0), capacity(1) {}

    void push(T value) {
        if (length >= capacity)
            grow();
        data[length++] = value;
    }

    void pop() {
        if (length <= 0.5*capacity)
            shrink();
        length--;
    }

    T top() {
        if (length <= 0)
            throw "empty stack";
        return data[length-1];
    }

    void print() {
        for (int i = length-1; i >= 0; --i)
            cout << data[i] << " ";
        cout << endl;
    }
};

template <typename T>
class Stack_linkedList {
    struct Node {
        T value;
        Node* next;

        Node(T value): value(value), next(nullptr) {}
    }* head;

    unsigned length;
public:
    Stack_linkedList(): head(nullptr), length(0) {}

    void push(T value) {
        Node* new_node = new Node(value);

        new_node->next = head;
        head = new_node;
        length++;
    }

    T pop() {
        if (length <= 0)
            throw "empty stack";

        Node* temp = head;
        T value = head->value;
        head = head->next;

        delete temp;
        length--;

        return value;
    }

    T top() {
        if (length <= 0)
            throw "empty stack";
        return head->value;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack_array<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.print();

    Stack_linkedList<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1.pop() << endl;

    s1.print();
    return 0;
}
