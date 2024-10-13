#include <iostream>
#include <string>

using namespace std;


void maze_solution(int arr[4][4], int size, int i, int j, string sol){

    
    if (i == size-1 && j == size-1 ){ cout << sol << endl; return;}

    arr[i][j] = 0;

    if(i+1 < size  && arr[i+1][j]){
    
        sol += "D"; 
        maze_solution(arr, 4, i+1, j, sol);
    }

    if(i-1 >= 0 && arr[i-1][j]) {

        sol += "U";
        maze_solution(arr, 4, i-1, j, sol);
    }

    if(j+1 < size  && arr[i][j+1]){

        sol += "R";
        maze_solution(arr, 4, i, j+1, sol);    
    }

    if(j-1 >= 0 && arr[i][j-1]){
        
        sol += "L";
        maze_solution(arr, 4, i, j-1, sol);
    }

    arr[i][j] = 1;
}

int main()
{
    int maze[4][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
    };

    maze_solution(maze, 4, 0, 0, "");

    return 0;
}
