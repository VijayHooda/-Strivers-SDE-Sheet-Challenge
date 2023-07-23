#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* links[26];
    int countendwith = 0;
    int countprefix = 0;

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
            node->inccrepref();
        }

        node->increend();
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

    int countWordsStartingWith(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containskey(word[i]))
            {
                return 0;
            }

            node = node->get(word[i]);
            
        }

        return node->countprefix;
    }

    void erase(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containskey(word[i]))
            {
                
                node = node->get(word[i]);
                node->reducepref();
            }

           
        }

        node->deleend();
    }
};
