#include <iostream>
#include <algorithm> // For reverse function
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

    bool empty() {
        return length == 0;
    }
};


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


string infix_to_postfix(string infix) {
    Stack_linkedList<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

      
        if (isalnum(c)) { 
            postfix += c;
        }
        
        else if (c == '(') {
            s.push(c);
        }
       
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        }
       
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c); 
        }
    }

   
    while (!s.empty()) {
        postfix += s.pop();
    }

    return postfix;
}


string infix_to_prefix(string infix) {
    Stack_linkedList<char> operators;
    Stack_linkedList<string> operands;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

       
        if (isalnum(c)) {
            string operand(1, c);
            operands.push(operand);
        }
        
        else if (c == '(') {
            operators.push(c);
        }
        
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.pop();

                
                string op1 = operands.pop();
                string op2 = operands.pop();
                string expr = op + op2 + op1;
                operands.push(expr);
            }
            operators.pop(); 
        }
       
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                char op = operators.pop();

                
                string op1 = operands.pop();
                string op2 = operands.pop();
                string expr = op + op2 + op1;
                operands.push(expr);
            }
            operators.push(c);
        }
    }

    
    while (!operators.empty()) {
        char op = operators.pop();

        string op1 = operands.pop();
        string op2 = operands.pop();
        string expr = op + op2 + op1;
        operands.push(expr);
    }

    return operands.pop(); 
}

\
int main() {
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";

    
    string postfix = infix_to_postfix(infix);
    cout << "Postfix: " << postfix << endl;

    
    string prefix = infix_to_prefix(infix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}
