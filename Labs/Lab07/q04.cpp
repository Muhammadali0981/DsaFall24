#include <iostream>
#include <vector>
using namespace std;


void countSort(int arr[], int n, int exp) {
    vector<int> output(n); 
    int count[10] = {0};   


    for (int i = 0; i < n; ++i) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    
    for (int i = n - 1; i >= 0; --i) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}


void radixSort(int arr[], int n, bool descending = false) {
    
    int maxNum = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxNum)
            maxNum = arr[i];

    
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countSort(arr, n, exp);

   
    if (descending) {
        for (int i = 0; i < n / 2; ++i)
            swap(arr[i], arr[n - i - 1]);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

 
    radixSort(arr, n);
    cout << "Sorted array in ascending order:\n";
    printArray(arr, n);

    
    radixSort(arr, n, true);
    cout << "Sorted array in descending order:\n";
    printArray(arr, n);

    return 0;
}
