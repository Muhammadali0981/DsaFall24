/*
    Name:Muhammad Ali
    Date:09/09/24
    Desc: sorting and searching
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


void bubble_sort(int* arr, int size){

    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
        if (flag) break;
    }
    
    print_arr(arr,size);
}

void selection_sort(int* arr, int size){
    for (int i = 0; i < 5; i++)
    {
        bool flag = true;
        int min_i = i;
        for (int j = i+1; j < 5; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
                flag = false;
            }
        }
        if (flag) break;
        if (min_i != i){
            swap(arr[min_i], arr[i]);
        }
            
    }

    print_arr(arr,size);

    return;
}

void insertion_sort(int* arr, int size){

    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    print_arr(arr,size);

    return;
}

int main()
{
    int array[5] = {9,6,4,2,10};

    cout << "Bubble sort: " << endl;
    bubble_sort(array, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "selection sort: " << endl;
    selection_sort(array, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "insertion sort: " << endl;
    insertion_sort(array, sizeof(array)/sizeof(array[0]));
    cout << endl;

    return 0;
}
