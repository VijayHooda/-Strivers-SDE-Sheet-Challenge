#include <bits/stdc++.h> 
using namespace std;

int f(int m, int w, int arr[], vector<vector<int>> dp){
    if (w==0) return 0;
    

}

int minsumofchildrenanger(int marbles, int wishes, int child_wishes[]){
    int n = sizeof(child_wishes)/sizeof(child_wishes[0]);

    vector<vector<int>> dp(marbles,(vector<int>(wishes,-1)));
    return f(marbles,wishes,child_wishes,dp);

}