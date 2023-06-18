using namespace std;
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back
 
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < size && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}


public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    int extractMin() {
        

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }
};



 

 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    MinHeap m;
    vector<int> ans;
    forn(i,n)
    {
        if (q[i][0]==0)
        {
            m.insert(q[i][1]);
        }
        else
        {
            int n = m.extractMin();
            ans.push_back(n);
        }
    }
    return ans;
}