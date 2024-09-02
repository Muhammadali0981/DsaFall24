/*
    Name:Muhammad Ali
    Date:02/09/24
    Desc: course managemnet using jageed array
*/

#include <iostream>

using namespace std;

int main()
{
    int rows = 4;

    int** jaggedArray = new int* [rows];
    jaggedArray[0] = new int[3];
    jaggedArray[1] = new int[4];
    jaggedArray[2] = new int[2];
    jaggedArray[3] = new int[1];


    return 0;
}
