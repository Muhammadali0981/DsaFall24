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
    int size[4] = {3,4,2,1};
    string dep[4] = {"SE","AI","CS","DS"};

    int** jaggedArray = new int* [rows];
    jaggedArray[0] = new int[3];
    jaggedArray[1] = new int[4];
    jaggedArray[2] = new int[2];
    jaggedArray[3] = new int[1];

    int temp[4][4] = {
        {78, 99, 86},     
        {90, 87, 67, 66}, 
        {80, 70},         
        {67}              
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < size[i]; ++j) {
            jaggedArray[i][j] = temp[i][j]; 
        }
    }

    for (int i = 0; i < rows; ++i) {
        cout << "Department " << dep[i] << " GPA: ";
        for (int j = 0; j < size[i]; ++j) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
