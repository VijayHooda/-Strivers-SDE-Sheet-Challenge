#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int mod = 1000000007;

int f(string& s, int i, int j, bool istrue, vector<vector<int>> dp){
    if (i>j) return 0;
    if (i==j){
        if (istrue==true) return s[i]==true;
        if (istrue==false) return s[i]==false;  
    }
    if (dp[i][j]!=-1) return dp[i][j];
    ll count;

    for (int k = i+1; k <= j-1; k+=2)
    {

        if (s[k]=='&') istrue=true;  count = (f(s,i,k-1,istrue,dp) * f(s,k+1,j,istrue,dp)) % mod;

        if (s[k]=='|') istrue=true;  count = (f(s,i,k-1,istrue,dp) * f(s,k+1,j,istrue,dp) + f(s,i,k-1,istrue,dp) * f(s,k+1,j,!(istrue),dp) +
                                             f(s,i,k-1,!(istrue),dp) * f(s,k+1,j,istrue,dp)) % mod;
        if (s[k]=='^') istrue=true;  count = (f(s,i,k-1,istrue,dp) * f(s,k+1,j,!(istrue),dp) +
                                             f(s,i,k-1,!(istrue),dp) * f(s,k+1,j,istrue,dp)) % mod;

        dp[i][j]=(count) % mod;
        
        
    }


    return dp[i][j];
}

int evaluateExp(string& exp) {
    int n = exp.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(exp,0,n-1,true,dp);
}