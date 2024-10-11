#include <iostream>

using namespace std;


int binary_sreach(int* arr, int mid, int high, int low, int t){
    
    if (arr[mid] == t) return mid;
    mid = (low + high)/2;
    if(arr[mid] < t) binary_sreach(arr, mid, high, mid, t);
    else if(arr[mid] > t) binary_sreach(arr, mid, mid, low, t);
    return -1;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    cout << binary_sreach(a, 0, 4, 0, 4) << endl;
}