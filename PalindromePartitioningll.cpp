#include <bits/stdc++.h> 
using namespace std;

void fillPalindromesTable(string &str, vector<vector<bool>> &p) {
    int n = str.size();
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                p[i][j] = true;
            } else if (gap == 1) {
                p[i][j] = (str[i] == str[j]);
            } else {
                p[i][j] = (str[i] == str[j]) && p[i + 1][j - 1];
            }
        }
    }
}

int f(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<bool>> &p) {
    if (i >= j || p[i][j]) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        if (dp[i][k]!=-1) int left = dp[i][k];
        else {int left = f(s, i, k, dp, p); left = dp[i][k];}

        if (dp[k+1][j]!=-1) int righ = dp[k+1][j];
        else {int righ = f(s, k+1, j, dp, p); righ = dp[k+1][j];}

        int temp = left + righ + 1;
        mini = min(mini, temp);
    }
    return dp[i][j] = mini;
}

int palindromePartitioning(string str) {
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<bool>> p(n, vector<bool>(n, false));
    fillPalindromesTable(str, p);
    return f(str, 0, n - 1, dp, p);
}
