#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

};

int countDistinctSubstrings(string &s)
{
    int c = 0;
    Node* root = new Node();
    for (int i = 0; i < s.size(); i++)
    {
        Node* node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containskey(s[j])){
                c++;
                node->put(s[j],new Node());
            }
            node = node->get(s[j]);
        }
        
    }

    return c+1;
}
