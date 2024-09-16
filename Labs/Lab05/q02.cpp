/*
    Name: Muhammad Ali
    Date: 16/09/24
    Desc: factorial using recusrion 
*/


#include <iostream>

using namespace std;

//non - tail recursion 
int non_tail_fact(int n){
    if(n == 1) return n;
    return n * non_tail_fact(n - 1);
}

//tail recusrion
int tail_fact(int n, int multiple){

    if(n == 1) return multiple;
    return tail_fact(n - 1, n * multiple);

    
}

int main()
{
    cout << non_tail_fact(5) << endl;
    cout << tail_fact(5, 1) << endl;
    return 0;
}
