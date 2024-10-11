#include <iostream>

using namespace std;



int fib(int n){

    if (n <= 2) return n - 1;
    else return fib(n - 1) + fib(n - 2);

}

int main(int argc, char const *argv[])
{
    cout << fib(4) << endl;
    return 0;
}
