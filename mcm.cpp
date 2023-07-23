
#include <bits/stdc++.h> 
using namespace std;

int f(int* arr, int i, int j,vector<vector<int>> &dp){
    if (i==j) return 0;
    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int mini = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + f(arr,i,k,dp) + f(arr,k+1,j,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
    
}

int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n,vector<int>(n,0));
    for (int i = n-1; i > 0; i++)
    {
        for (int j = i+1; j < n; j++)
        {
             int mini = INT_MAX;
        
        for (int k = i; k <= j-1; k++)
        {
            int steps = arr[i-1]*arr[k]*arr[j] + f(arr,i,k,dp) + f(arr,k+1,j,dp);
            mini = min(mini,steps);
        }
            dp[i][j] = mini;
        }
        
    }
  

    return dp[1][n-1];
    
}