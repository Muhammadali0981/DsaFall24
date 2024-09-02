/*
    Name:Muhammad Ali
    Date:02/09/24
    Desc: finds common friends
*/

#include <iostream>

using namespace std;


bool checkfriends(bool arr[5][5],int i, int j){
    
    for (int k = 0; k < 5; k++)
    {
        if(arr[i][k] && arr[j][k]) return true;
    }
    return false;
}
int main()
{
    bool friends[5][5] = {{0,1,0,1,1},{1,0,1,0,1},{0,1,0,0,0},{1,0,0,0,1},{1,1,0,1,0}};
    cout << checkfriends(friends, 0, 4) << endl;
    cout << checkfriends(friends, 1, 2) << endl;
    return 0;
}
