#include <bits/stdc++.h> 
using namespace std;


struct Node{
    Node* links[26];
    int countendwith = 0;
    int countprefix = 0;
    bool flag = false;

    void setend(){
        flag = true;
    }

    bool isend(){
        return flag;
    }

    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    void increend(){
        countendwith++;
    }

    void inccrepref(){
        countprefix++;
    }

    void deleend(){
        countendwith--;
    }

    void reducepref(){
        countprefix--;
    }
};

class Trie{

    private: Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i],new Node());

            }

            node = node->get(word[i]);
            
        }

        node->setend();
    }
     int countWordsEqualTo(string &word){
        Node* node = root;
         for (int i = 0; i < word.size(); i++)
        {
            if (!node->containskey(word[i]))
            {
                return 0;
            }

            node = node->get(word[i]);
            
        }

        return node->countendwith;
        
    }

    bool ifprefixexists(string word){
        bool f = true;
        Node* node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (node->containskey(word[i])){
                node=node->get(word[i]);
                if (node->isend()==false) return false;

            }
            return false;
        }
        return true;
        
    }
};

 string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie trie;
    for(auto it:arr){
        trie.insert(it);
    }

    string s="";

    for(auto it: arr){
        if (trie.ifprefixexists(it)){
            if (it.length() > s.length()){
                s = it;
            }

            else if (it.length() == s.length() && it>s)
            {
                s = it;
            }

            
        }
    }

    if (s=="") return "None";
    return s;
}