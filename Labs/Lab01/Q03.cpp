/*
    Programmer: Muhammad Ali
    Date: 19/8/24
    Descrpetion: Exam class code to show deep copy
*/

#include <iostream>

using namespace std;

class Document {
private:
    string *text;
public:
    Document(){
        text = nullptr;
    }
    Document(const string& text){
        this->text = new string(text);
    }
    Document(const Document& obj){
        text = new string(*obj.text);
    }
    
    ~Document() { 
        delete text; 
    }

    Document& operator = (const Document& obj) {
        if (this == &obj) return *this;
        delete text;
        text = new string(*obj.text);
        return *this;
    }

    void print(){ 
        cout << *text << endl; 
    }

    void settext(const string& text) {
        delete this->text;
        this->text = new string(text);
    }
};

int main() {
    Document doc1("some data");
    Document doc2(doc1);
    Document doc3;
    doc3 = doc1;

    doc1.settext("some new data");

    doc1.print();
    doc2.print();
    doc3.print();

    return 0;
}
