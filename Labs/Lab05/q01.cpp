/*
    Name:Muhammad Ali
    Date: 16/09/24
    Desc: sorting array using recursion
*/

#include <iostream>

using namespace std;


void print_arr(int* arr, int size){
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
   
    return;

}

int* recursive_sort(int i, int *arr, int size){

    if(i > size) return arr;

    else{
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);

            }
        }
        return recursive_sort(i+1, arr, size);
    }

}


int main()
{
    int arr[5] = {4, 3, 5, 9 ,1};
    int* sorted_arr = recursive_sort(0, arr, 5);
    print_arr(sorted_arr, 5);
    return 0;
}

