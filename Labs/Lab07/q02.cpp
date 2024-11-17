#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int finishTime;
};


void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].finishTime <= R[j].finishTime) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}


void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int numParticipants = 10;
    Runner participants[10];

    cout << "Enter the participant names and their finish times:\n";
    for (int i = 0; i < numParticipants; ++i) {
        cout << "Name of participant " << (i + 1) << ": ";
        cin >> participants[i].name;
        cout << "Finish time (in seconds) of participant " << (i + 1) << ": ";
        cin >> participants[i].finishTime;
    }

    mergeSort(participants, 0, numParticipants - 1);

    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; ++i) {
        cout << participants[i].name << " - " << participants[i].finishTime << " seconds\n";
    }

    return 0;
}
