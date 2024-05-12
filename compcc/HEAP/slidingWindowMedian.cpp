#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    // Constructor that initializes the finder with a window size 'k'.
    MedianFinder(int k) : windowSize(k), smallSize(0), largeSize(0) {}

    // Adds a number into the data structure.
    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        // Ensure the heaps are balanced after the insertion.
        rebalanceHeaps();
    }

    // Removes a number from the data structure.
    void removeNum(int num) {
        delayed[num]++;
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        // Ensure the heaps are balanced after the removal.
        rebalanceHeaps();
    }

    // Returns the median of current numbers.
    double findMedian() {
        if (windowSize & 1) {
            return small.top();
        } else {
            return (static_cast<double>(small.top()) + large.top()) * 0.5;
        }
    }

private:
    // Max heap to store the smaller half of the elements
    std::priority_queue<int> small;
    // Min heap to store the larger half of the elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;
    // Hashmap to keep track of delayed removals when numbers are out of the current window
    std::unordered_map<int, int> delayed;
    // Sizes of the heaps
    int smallSize, largeSize;
    // Window size
    int windowSize;

    // Prunes/removes elements from the heap that should be delayed-removed.
    template <typename T>
    void prune(T& heap) {
        while (!heap.empty() && delayed[heap.top()]) {
            if (--delayed[heap.top()] == 0) {
                delayed.erase(heap.top());
            }
            heap.pop();
        }
    }

    // Balances the two heaps to maintain the median property.
    void rebalanceHeaps() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            // Re-prune in case the top element is meant to be delayed-removed.
            prune(small);
        } else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            // Re-prune in case the top element is meant to be delayed-removed.
            prune(large);
        }
    }
};

class Solution {
public:
    // Calculates the median for each window of size 'k' in the array.
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
        MedianFinder finder(k);
        // Initialize by adding the first 'k' elements.
        for (int i = 0; i < k; ++i) {
            finder.addNum(nums[i]);
        }
        // Store the first median.
        std::vector<double> medians = {finder.findMedian()};
        // Slide the window, one element at a time, maintaining the median.
        for (int i = k; i < nums.size(); ++i) {
            finder.addNum(nums[i]); // Add the new element to the window.
            finder.removeNum(nums[i - k]); // Remove the element that is no longer in the window.
            // Store the new median.
            medians.push_back(finder.findMedian());
        }
        return medians;
    }
};

int main() {
    std::vector<int> v = {1,3,-1,-3,5,3,6,7};
    int windowSize = 3;
    Solution obj;
    std::vector<double> ans = obj.medianSlidingWindow(v, windowSize); 
    for (auto num : ans) {
        std::cout << num << " ";
    }
    return 0;
}
