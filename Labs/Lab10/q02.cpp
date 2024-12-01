#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findKLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; 

    for (int num : nums) {
        minHeap.push(num);

        
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 3;

    vector<int> result = findKLargest(nums, k);
    cout << "K largest elements: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}