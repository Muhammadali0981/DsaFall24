#include <iostream>
#include <vector>

using namespace std;
// Custom max heap class
class MaxHeap {
private:
    vector<pair<int, int>> heap; // {value, index}

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].first < heap[index].first) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left].first > heap[largest].first) {
                largest = left;
            }

            if (right < size && heap[right].first > heap[largest].first) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(int val, int index) {
        heap.push_back({val, index});
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    pair<int, int> top() {
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    void removeOutdatedElements(int windowStart) {
        heap.erase(
            remove_if(heap.begin(), heap.end(), 
                [windowStart](const pair<int, int>& elem) { 
                    return elem.second <= windowStart; 
                }), 
            heap.end()
        );
        
        // Rebuild heap after removing elements
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    MaxHeap maxHeap;
    
    // Process first window
    for (int i = 0; i < k; ++i) {
        maxHeap.push(nums[i], i);
    }
    
    // Add first window's maximum
    result.push_back(maxHeap.top().first);
    
    // Process remaining windows
    for (int i = k; i < nums.size(); ++i) {
        // Add current element
        maxHeap.push(nums[i], i);
        
        // Remove elements outside current window
        maxHeap.removeOutdatedElements(i - k);
        
        // Add maximum of current window
        result.push_back(maxHeap.top().first);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindow(nums, k);
    
    cout << "Sliding Window Maximums: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
