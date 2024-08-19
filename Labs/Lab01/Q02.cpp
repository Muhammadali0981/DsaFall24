/*
    Programmer: Muhammad Ali
    Date: 19/8/24
    Descrpetion: Exam class code to show shallow copy
*/


#include <iostream>

using namespace std;

class Exam {
private:
    string *name,*date;
    int *score;
public:
    Exam(){
        name = nullptr;
        score = nullptr;
        date = nullptr;
    }

    void setname(string name) {
        delete this->name;
        this->name = new string(name);
    }

    void setscore(int score) {
        delete this->score;
        this->score = new int(score);
    }

    void setdate(string date) {
        delete this->date;
        this->date = new string(date);
    }

    void display(){
        cout << "Name : " << *name << "\nScore: " << *score << "\nDate : " << *date << endl; 
    }
};

int main() {
    Exam exam1;
    exam1.setname("Ali");
    exam1.setscore(65);
    exam1.setdate("8/19/24");

    Exam exam2(exam1);
    
    cout << "before assigning values to exam2" << endl;
    exam1.display();
    exam2.display();
    
    exam2.setscore(70);

    cout << "\nafter updating score in exam 2" << endl;
    exam1.display();
    exam2.display();

    cout << "we will see upadte in both" << endl;
    return 0;
}