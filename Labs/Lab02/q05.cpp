/*
    Name:Muhammad Ali
    Date:02/09/24
    Desc: seating mangement
*/

#include<iostream>

using namespace std;

int main(){

    string **chart = new string*[4];
    int *cap = new int[4];

    for(int i = 0; i < 4; i ++) {
        
        int c = 0;
        cout<< "Enter capacity for row number " << i+1 << " : ";
        cin>> c;

        cap[i] = c;
        chart[i] = new string[c];

        for(int j = 0; j < c; j++) {
            cout<< "Enter the name of person for " << i+1 << " row,seat  " << j+1 << " : ";
            cin>> chart[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        cout<< "People in row " << i+1 << ":" << endl;
        for(int j = 0; j < cap[i]; j++) {
            cout<< "Name " << j+1 << ": " << chart[i][j] << endl;
        }
        cout << endl;
        delete[] chart[i];
    }

    delete[] chart;

    return 0;
}
