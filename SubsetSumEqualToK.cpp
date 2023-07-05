#include <bits/stdc++.h> 
using namespace std;


bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<vector<bool>> dp(n,vector<bool>(k+1,false));
   for (int i = 0; i < n; i++)
   {
    dp[i][0]=true;
   }
    if (k>=arr[0]) {dp[0][arr[0]]=true;}
   
   for (int i = 1; i < n; i++)
   {
     for (int j = 1; j <= k; j++)
    {
        
        bool nottake = dp[i-1][j];
        bool take = false;
        if (j>=arr[i]) {take = dp[i-1][ j-arr[i]];}
        dp[i][j] = take || nottake;
        
     }
     }
    
    return dp[n-1][k];
     
   }
   
   

   


