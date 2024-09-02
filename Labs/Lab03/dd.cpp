#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) {}
    Node(int value) : value(value), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    LinkedList() : head(nullptr) {}
    LinkedList(Node* head) : head(head) {}
    void Insert_at_Head(int value) {
      Node* newNode = new Node(value);
      newNode->next = head;
      head = newNode;
    }

    void Insert_at_Tail(int value) {
      
      Node* newNode = new Node(value);
      if (head == nullptr) {
        head = newNode;
        return;
      }
      Node* current = head;
      while (current -> next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
      return;
    }

    void Insert_Infront_of_Value(int newvalue, int placevalue) {
      if (head == nullptr) { 
        std::cout << "PlaceHolder Value Not Found" << std::endl;
        return; 
      }
      Node* current = head;
      Node* newNode = new Node(newvalue);
      while (current != nullptr && current -> next -> value != placevalue) {
        current = current->next;
      }
      if (current -> next == nullptr) {
        std::cout << "PlaceHolder Value Not Found" << std::endl;
        return; 
      }
      newNode->next = current->next;
      current->next = newNode;
    }

    void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }
    head = prev; 
}

    void Insert_Behind_Value(int newvalue, int placevalue) {
      if (head == nullptr) {
        std::cout << "PlaceHolder Value Not Found" << std::endl;
        return; 
      }
      if (head->value == placevalue) {
        Insert_at_Head(newvalue);
        return;
      }
      Node* newNode = new Node(newvalue);
      Node* current = head;
      while (current->next->value != placevalue && current->next != nullptr) {
        current = current->next;
      }
      if (current == nullptr) {
        std::cout << "PlaceHolder Value Not Found" << std::endl;
        delete newNode;
        return; 
      }
      newNode->next = current->next;
      current->next->next = newNode;
    }

    void Insert_at_Both_Ends(int headvalue, int tailvalue) {
      Insert_at_Tail(tailvalue);
      Insert_at_Head(headvalue);
    }

    void Delete_at_Head() {
      if (head == nullptr) return;
      Node* current = head;
      head = head->next;
      delete current;
    }

    void Delete_at_Tail() {
      if (head == nullptr) return;
      if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
      }
      Node* current = head;
      while (current -> next -> next != nullptr) {
        current = current -> next;
      }
      delete current -> next;
      current -> next = nullptr;
    }

    void Delete_Value(int value) {
      if (head == nullptr) return;
      if (head->value == value) {
        Delete_at_Head();
        return;
      }
      Node* current = head;
      while (current -> next != nullptr) {
        if (current->next->value == value) break;
        current = current->next;
      }
      if (current -> next == nullptr) {
        std::cout << "PlaceHolder Value Not Found" << std::endl;
        return;
      }
      Node* temp = current->next;
      current->next = current->next->next;
      delete temp; 
    }

    int Count_Nodes() {
      int ans = 0;
      Node* current = head;
      while (current != nullptr) {
        current = current->next;
        ans++;
      }
      return ans;
    }
    void print() {
      if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
      }
      Node* current = head;
      while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
          std::cout << " -> ";
        }
        current = current->next;
      }
      std::cout << " : End of List\n";
    }
};

int main() {
  LinkedList List;
  List.Insert_at_Head(10);
  List.Insert_at_Head(11);
  List.Insert_at_Head(12);
  List.Insert_at_Head(13);
  List.print();
  List.Insert_at_Tail(20);
  List.Insert_at_Tail(21);
  List.Insert_at_Tail(22);
  List.Insert_at_Tail(23);
  List.print();
  List.Delete_at_Head();
  List.Delete_at_Tail();
  List.Delete_Value(23);
  List.print();
  List.Insert_Infront_of_Value(78,13);
  List.Insert_Infront_of_Value(79,23);
  List.Insert_Behind_Value(67,21);
  List.Insert_Behind_Value(68,23);
  List.print();
  List.reverse();
  List.print();
}