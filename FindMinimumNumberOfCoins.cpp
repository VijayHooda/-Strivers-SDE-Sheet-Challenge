
#include <bits/stdc++.h> 
using namespace std;
#include <iostream>
#include <vector>
#include <utility>
#define forn(i, n) for (int i = 0; i < int(n); i++)
int findMinimumCoins(int amount) 
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(100);
    v.push_back(500);
    v.push_back(1000);
    int c=0;
    int i=0;
    while (amount>=v[i])
    {
        i++;
    }
    if (amount==v[i])
    {
        return 1;
    }
    else
    {
        i--;
        while (amount!=0)
        {
            c+=amount/v[i];
            amount%=v[i];
            i--;

        }
        return c;
        
    }
    
    
    

}


