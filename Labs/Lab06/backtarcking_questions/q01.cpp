#include <iostream>
#include <string>

using namespace std;


void maze_solution(int arr[4][4], int size, int i, int j, string sol){

    
    if (i == size-1 && j == size-1 ){ cout << sol << endl; sol = ""; return;}

    if(i + 1 > size || i < 0 || j < 0 || j + 1 > size  || arr[i][j] == 0) return;
    arr[i][j] = 0;


    maze_solution(arr, 4, i+1, j, sol + "D");
    maze_solution(arr, 4, i-1, j, sol + "U");
    maze_solution(arr, 4, i, j+1, sol + "R");    
    maze_solution(arr, 4, i, j-1, sol + "L");
    
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
