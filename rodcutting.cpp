#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n,vector<int>(w+1,0));
    
    for (int i=0;i<=w;i++){
        int j = i / weight[0];
        dp[0][i]=j*profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int nottake = dp[i-1][j];
            int take = 0;
            if (weight[i]<=j) take = profit[i] + dp[i][j-weight[i]];
            dp[i][j] = max(nottake,take);

        }

    }

    return dp[n-1][w];
}

int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1,0); 
    int startIndex = 1; 
    int endIndex = price.size(); 

    std::vector<int> newVector(endIndex - startIndex + 1); 
    for (int i = startIndex; i <= endIndex; i++) {
        newVector[i - startIndex] = price[i];
    }

    vector<int> weight(n); 
    
    for (int i = 0; i < n; i++) {
        weight[i] = i + 1;
    }

    return unboundedKnapsack(n,n,price,weight);




}
