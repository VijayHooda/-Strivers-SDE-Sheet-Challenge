#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
    if (i>j) return 0;

    if (dp[i][j]!=-1) return dp[i][j];
    int maxi = INT_MIN;
        
    for (int ind = i; ind <= j; ind++) 
    {
            int cost = arr[i - 1]*arr[ind]*arr[j + 1] + f(i, ind - 1, arr, dp) + f(ind + 1, j, arr, dp);
            maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

    


int main()
{
    int n;
    cin>>n;
    vector<int> arr;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    
    cout<<f(1,n,arr,dp)<<endl;

    return 0;
}