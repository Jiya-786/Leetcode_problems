// Last updated: 30/06/2026, 19:33:44
// class MedianFinder {
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
        
//     }
    
//     double findMedian() {
        
//     }
// };

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */

 #include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // max heap for left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap for right half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Step 1: add to max heap
        maxHeap.push(num);

        // Step 2: balance order
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: balance size
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
