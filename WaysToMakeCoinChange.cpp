#include <bits/stdc++.h> 
using namespace std;

long countWaysToMakeChange(int *num, int n, int value)
{
    vector<vector<long long int>> dp(n,vector<long long int>(value+1,0));

    for (int i = 0; i <= value; i++)
    {
        if (!(i%num[0])) dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < value+1; j++)
        {
            long long int nottake = dp[i-1][j];
            long long int take = 0;
            if (num[i]<=j) take =  dp[i][j-num[i]];
            dp[i][j] = nottake + take;
        }
        
    }

    return dp[n-1][value];
}