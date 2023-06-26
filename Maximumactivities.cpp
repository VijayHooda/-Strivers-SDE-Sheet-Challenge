    #include <bits/stdc++.h> 
    using namespace std;

    bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; 
    }

    vector<pair<int, int>> makePairsAndSort(vector<int>& vector1, vector<int>& vector2) {
        vector<pair<int, int>> pairs;
        for (size_t i = 0; i < vector1.size(); i++) {
            pairs.push_back(make_pair(vector1[i], vector2[i]));
        }

        sort(pairs.begin(), pairs.end(), comparePairs); 

        return pairs;
        
    }
    int maximumActivities(vector<int> &start, vector<int> &finish) {
        int c=1;
        vector<pair<int,int>> pairs = makePairsAndSort(start,finish);
        int limit=pairs[0].second;
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i].first>=limit)
            {
                c++;
                limit=pairs[i].second;
            }
        }
        return c;
        
    }
int main(){
    vector<int> a = {1,1,1};
    vector<int> b = {4,5,9};
    cout<<maximumActivities(a,b);
}