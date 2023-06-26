#include <bits/stdc++.h> 
using namespace std;
#include <iostream>
#include <vector>
#include <utility>
#define forn(i, n) for (int i = 0; i < int(n); i++)

#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

void ct(long long c) {
    cout << c << endl;
}

std::vector<std::pair<int, int>> convertToPairs(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::pair<int, int>> result;

    for (const auto& row : matrix) {
        if (row.size() == 2) {
            result.emplace_back(row[0], row[1]);
        } 
    }

    return result;
}


int jobScheduling(vector<vector<int>> &jobs)
{
    int pr=0;
    std::vector<std::pair<int, int>> pairs = convertToPairs(jobs);
    std::sort(pairs.begin(), pairs.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });
     int maxfirst = std::max_element(pairs.begin(), pairs.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        })->first;

    int arr[maxfirst]={0};
    
    



}
