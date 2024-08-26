/*
    Name:Muhammad Ali
    Date:26/08/24
    Desc: jagged arrays 
*/

#include <iostream>

using namespace std;


int main(){
    
    int rows = 5;
    int size = 0;
    int arr[5] = {0, 0, 0, 0, 0};

    int** jaggedArray = new int* [rows];
    
    for(int i = 0; i < rows; i++)
    {
        cout << "enter size of array on row" << i+1 << ": ";
        cin >> size ;
        cout << endl;
        arr[i] = size;
        jaggedArray[i] = new int[size];

        for (int j = 0; j < size; j++)
        {
            
            cout << "enter element " << j+1 << "of array" << i+1 << ":";
            cin >> jaggedArray[i][j];
            cout << endl;       
        }
        
        
    }
    for(int k = 0; k < rows; k++)
    {
        for(int l = 0; l < arr[k]; l++){
            cout << jaggedArray[k][l];
    
        }
        cout << "\n";
    
    }
    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    for(int i = 0; i < rows; i++){
        int* temp_arr = new int[10];

        for(int j = 0; j < arr[i]; j++) temp_arr[j] =  jaggedArray[i][j];
        
        for(int j = arr[i]; j < 10; j++) temp_arr[j] = 0;

        delete[] jaggedArray[i];
        jaggedArray[i] = temp_arr;
    }
        
    return 0;
}
