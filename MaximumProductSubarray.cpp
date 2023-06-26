#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int p1 = arr[0],p2 = arr[0],r = arr[0];
    
    for(int i=1;i<arr.size();i++) {
        int temp = max({arr[i],p1*arr[i],p2*arr[i]});
        p2 = min({arr[i],p1*arr[i],p2*arr[i]});
        p1 = temp;
        
        r = max(r,p1);
    }
    
    return r;

}
