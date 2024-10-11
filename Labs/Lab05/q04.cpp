#include <iostream>

using namespace std;


int binary_search(int* arr, int low, int high, int t){
    
    if (low > high) return -1;  

    int mid = (low + high) / 2;

    if (arr[mid] == t) return mid;   
    if (arr[mid] < t) return binary_search(arr, mid + 1, high, t);  
    else return binary_search(arr, low, mid - 1, t);  
    return -1;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    cout << binary_search(a, 0, 4, 4) << endl;
}