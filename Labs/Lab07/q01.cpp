#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


Node* partition(Node* start, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = start;
    Node* tail = pivot;

    *newHead = nullptr;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*newHead == nullptr) {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            Node* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == nullptr) {
        *newHead = pivot;
    }

    *newEnd = tail;
    return pivot;
}


Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) {
        return head;
    }

    Node* newHead = nullptr;
    Node* newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}


Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}


void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


Node* createSampleList() {
    int data[] = {10, 7, 8, 9, 1, 5, 3};
    Node* head = new Node(data[0]);
    Node* current = head;

    for (int i = 1; i < 7; ++i) {
        current->next = new Node(data[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Node* head = createSampleList();
    cout << "Original List: ";
    printList(head);

    head = quickSortRecur(head, getTail(head));

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
