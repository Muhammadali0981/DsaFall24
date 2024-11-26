#include "BST.h"
#include <iostream>
#include <string>

using namespace std;


int main(){

    Bst myData;

    myData.insert(52, "Ali", 19);
    myData.insert(18, "Fasih", 19);
    myData.insert(47, "Owais", 22);
    myData.insert(30, "Abser", 19);
    myData.insert(56, "Layyana", 20);
    myData.insert(6, "Laiba", 20);

    myData.display();

    auto result = myData.search(56);
    if (result)
        cout << "Found: " << result->ID << " " << result->Name << " " << result->Age << endl;
    
    return 0;

}
