#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
using namespace std;


vector<vector<bool>> subsetSumToK(int n, int k, vector<int> &arr) {
   vector<vector<bool>> dp(n,vector<bool>(k+1,false));
   for (int i = 0; i < n; i++)
   {
    dp[i][0]=true;
   }
    if (k>=arr[0]) dp[0][arr[0]]=true;
   
   for (int i = 1; i < n; i++)
   {
     for (int j = 1; j <= k; j++)
     {
        
        bool nottake = dp[i-1][j];
        bool take = false;
        if (j>=arr[i]) take = dp[i-1][ j-arr[i]];
        dp[i][j] = take || nottake;
        
     }
   }
    
    return dp;
     
   }


int minSubsetSumDifference(vector<int>& arr, int n)
{
    long long int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    
    vector<vector<bool>> dp = subsetSumToK(n,sum/2,arr);

    if (sum%2==0) {
        for (int i=sum/2; i>=0; i--){
            if(dp[n-1][i]) return 2*(sum/2-i);
        }
    }
    
    if (sum%2!=0) {
        for (int i=sum/2; i>=0; i--){
            if(dp[n-1][i]) return 2*(sum/2-i) + 1;
        }
    }
    
    
    // if (sum%2==0)
    // {
    //     for (int i = 0; i < (sum/2+1); i++)
    //     {
    //         if (subsetSumToK(n,sum/2 - i,arr)) return 2*i;
    //     }
        
    // }

    // if (sum%2!=0)
    // {
    //     for (int i = 0; i < (sum/2+1); i++)
    //     {
    //         if (subsetSumToK(n,(sum/2)-i,arr)) return 2*i +1;
    //     }
        
    // }
    
}