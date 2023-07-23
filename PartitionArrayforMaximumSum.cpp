#include <bits/stdc++.h> 
using namespace std;

int f(vector<int> &num, int ind, int k, vector<int>& dp){
    int n = num.size();
    if (ind==n) return 0;
    if (dp[ind]!=-1) return dp[ind];
    int l = 0;
    int maxi1 = INT_MIN, maxi2 = INT_MIN;
    for (int j = ind; j < min(ind+k,n); j++)
    {
        l++;
        maxi1 = max(maxi1,num[j]);
        maxi2 = max(maxi2,maxi1*l + f(num, j, k,dp));
        dp[j] = maxi2;
    }
    return dp[ind];
    
}

int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp (n+1,-1);
    return f(num,0,k,dp);

}