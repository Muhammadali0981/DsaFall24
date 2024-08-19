/*
    Programmer: Muhammad Ali
    Date: 19/8/24
    Descrpetion: bank account class code to show conctrutor overloading 
*/
#include <iostream>

using namespace std;

class bank_account {
private:
    double *amount;
public:
    bank_account(){
        this->amount = new double(0.0);
    }
    bank_account(double amount){
        this->amount = new double(amount);
    }
    bank_account(const bank_account& obj){
        this->amount = new double(*obj.amount);
    }

    void withdraw(double x) {
        if (x > *amount){
            cout << "there arent enough cerdits" << endl;
        }
        
        else{
            *amount -= x;
        }
    }

    int get_amount(){
        return *amount;
    }
   
};

int main() {
    bank_account a1;
    bank_account a2(1000);
    bank_account a3(a2);

    a3.withdraw(200);

    cout << "account 1 = " << a1.get_amount() << endl;
    cout << "account 2 = " << a2.get_amount() << endl;
    cout << "account 3 = " << a3.get_amount() << endl;

    return 0;
}
