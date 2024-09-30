#include <iostream>

using namespace std;


struct Node{

    Node* next;
    int data;

    Node(int data): data(data), next(nullptr){};
};


class Stack{
public:

    Node* head;

    Stack() : head(nullptr) {}

    void push(int data){
        
        Node* new_node = new Node(data);

        if(!head) head = new_node;

        else{
            new_node->next = head;
            head = new_node;
        }

    }

    int pop_value(){
        
        int d = -1;

        if(!head){
            cout << "empty stack add values" << endl;
            return d;
        } else{
            Node* temp = head;
            head = head->next;
            d = temp->data;
            delete temp;
        }
    return d;
    }

    void print() {
        
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }


    void separate_odd_even(){
        
        Stack even;
        Stack odd;
        
        while(this->head != nullptr){
            
            int value = this->pop_value();
            if(value%2 == 0) even.push(value);
            if(value%2 != 0) odd.push(value);
            
        }
        
        cout << "Even stack" << endl;
        even.print();
        cout << "Odd stack" << endl;
        odd.print();

        return;
    } 

};


int main()
{
    int arr_of_nums[10] = {2, 1, 6, 5, 9, 10, 11, 19, 18 ,32};
    Stack nums;
    
    for(int i = 0; i < 10; i++){
        nums.push(arr_of_nums[i]);
    }

    cout << "vales added" << endl;
    nums.print();

    nums.separate_odd_even();
    
    return 0;
}
