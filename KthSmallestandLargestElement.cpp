#include <bits/stdc++.h>
 
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> a;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size()>k)
        {
            maxHeap.pop();
        }
        
    }
    a.push_back(maxHeap.top());
    priority_queue<int> maxHeap1;
    int j = (n-k)+1;
    for (int i = 0; i < arr.size(); i++)
    {
        maxHeap1.push(arr[i]);
        if (maxHeap1.size()>j)
        {
            maxHeap1.pop();
        }
        
    }
    a.push_back(maxHeap1.top());

    return a;
}