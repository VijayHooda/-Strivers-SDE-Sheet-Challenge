#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

int findWays(vector<int>& arr, int k)
{
	
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
     if(arr[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1;  // 1 case -pick
    
    if (k<=arr[0]) dp[0][arr[0]]=1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {   
        
            int nottake = dp[i-1][j];
            int take = 0;
            if (j>=arr[i]) {take = dp[i-1][ j-arr[i]];}
            dp[i][j] = (take + nottake)%mod ;
        
        }
    }

    return dp[n-1][k];
}