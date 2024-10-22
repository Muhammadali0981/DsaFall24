#include <iostream>
using namespace std;


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

    bool isEmpty() {
        return length == 0;
    }
};


class QueueUsingStacks {
    Stack_linkedList<int> stack1;  
    Stack_linkedList<int> stack2;  

public:
    
    void enqueue(int x) {
        stack1.push(x);
        cout << x << " enqueued into queue." << endl;
    }

    
    int dequeue() {
        
        if (stack1.isEmpty() && stack2.isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        
        return stack2.pop();
    }

    // Display the front element of the queue
    int front() {
        if (stack1.isEmpty() && stack2.isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        if (!stack2.isEmpty()) {
            return stack2.top();
        } else {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
            return stack2.top();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front of queue: " << queue.front() << endl; // Should print 10

    cout << "Dequeued: " << queue.dequeue() << endl; // Should print 10
    cout << "Dequeued: " << queue.dequeue() << endl; // Should print 20

    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Front of queue: " << queue.front() << endl; // Should print 30

    cout << "Dequeued: " << queue.dequeue() << endl; // Should print 30
    cout << "Dequeued: " << queue.dequeue() << endl; // Should print 40
    cout << "Dequeued: " << queue.dequeue() << endl; // Should print 50
    cout << "Dequeued: " << queue.dequeue() << endl; // Should print "Queue is empty"

    return 0;
}
