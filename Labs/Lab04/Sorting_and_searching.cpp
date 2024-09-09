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

void copy_arr(int* source, int* dest, int size){
    for(int i = 0; i < size; i++){
        dest[i] = source[i];
    }
}

void bubble_sort(int* arr, int size){

    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        for (int j = 0; j < size - 1; j++)
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

void shell_sort(int* arr, int size){

    for(int gap = size / 2; gap > 0; gap /=2){
        for(int i = gap; i < size; i++){
            int key = arr[i];

            int j;
            for(j = i; j >= gap && arr[j - gap] > key; j -= gap){
                arr[j] = arr[j - gap];
            } 

            arr[j] = key;
        }
    }

    print_arr(arr,size);

    return;
}

void comb_sort(int* arr, int size){

    int gap = size;

    bool sorted = false;

    while (gap > 1 || !sorted) {
        
        gap /= 1.3;
        if (gap < 1) gap = 1;
        
        sorted = true;

        for (int i = 0; i + gap < size; i++) {
            
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                
                sorted = false;
            }
        }
    }

    print_arr(arr,size);
}

int linear_search(int* arr, int size, int key){
    
    for(int i = 0; i < size; i++){
        if (arr[i] == key) return i;

    }
    return -1;
    
}


int binary_sreach(int* arr, int size, int key){
    
    //sorting first
    for(int gap = size / 2; gap > 0; gap /=2){
        for(int i = gap; i < size; i++){
            int key = arr[i];

            int j;
            for(j = i; j >= gap && arr[j - gap] > key; j -= gap){
                arr[j] = arr[j - gap];
            } 

            arr[j] = key;
        }
    }

    int low = 0;
    int high = size - 1;
    
    while (low <= high){
        int mid = (low+high)/2;

        if(arr[mid] == key) return mid;
        else if (arr[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}

int interpolation_sreach(int* arr, int size, int key){
    
    //sorting first
    for(int gap = size / 2; gap > 0; gap /=2){
        for(int i = gap; i < size; i++){
            int key = arr[i];

            int j;
            for(j = i; j >= gap && arr[j - gap] > key; j -= gap){
                arr[j] = arr[j - gap];
            } 

            arr[j] = key;
        }
    }

    int low = 0;
    int high = size - 1;
    
    while (low <= high){
        int pos = low + ((key - arr[low]) * (high - low))/(arr[high] - arr[low]);

        if(arr[pos] == key) return pos;
        else if (arr[pos] > key){
            high = pos - 1;
        }else{
            low = pos + 1;
        }
    }

    return -1;
}

int main()
{
    int array[5] = {9,6,4,2,10};
    int temp[5];

    cout << "Bubble sort: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0])); 
    bubble_sort(temp, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "selection sort: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0])); 
    selection_sort(temp, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "insertion sort: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0])); 
    insertion_sort(temp, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "shell sort: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0])); 
    shell_sort(temp, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "comb sort: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0])); 
    comb_sort(temp, sizeof(array)/sizeof(array[0]));
    cout << endl;

    cout << "linear sreach for 4: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0]));
    cout << "found at index: "<< linear_search(temp, sizeof(array)/sizeof(array[0]), 4);
    cout << endl;
    
    cout << "binary sreach for 4: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0]));
    cout << "found at index: "<< binary_sreach(temp, sizeof(array)/sizeof(array[0]), 4);
    cout << endl;
    
    cout << "interpolation sreach for 4: " << endl;
    copy_arr(array, temp, sizeof(array)/sizeof(array[0]));
    cout << "found at index: "<< interpolation_sreach(temp, sizeof(array)/sizeof(array[0]), 4);
    cout << endl;

    return 0;
}
