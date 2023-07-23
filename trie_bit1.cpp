    #include <bits/stdc++.h> 
    using namespace std;

    struct Node{
        Node* links[2];
    

        bool containskey(int i){
            return (links[i]!=NULL);
        }

        Node* get(int i){
            return links[i];
        }

        void put(int i, Node* node){
            links[i]=node;
        }
    };
    class Trie{

        private: Node* root;

        public:

        Trie(){
            root = new Node();
        }

        void insert(int n){
            Node* node = root;
            for (int i = 31; i >=0; i--)
            {
                int bit = (n>>i) & 1;
                if (!node->containskey(bit))
                {
                    node->put(bit,new Node());

                }

                node = node->get(bit);
                
            }
        }

        int getmax(int n){
                int maxi = 0;
                Node* node = root;
                for (int i = 31; i >=0; i--)
                {
                    int bit = (n>>i) & 1;
                    if (node->containskey(1-bit)){
                        maxi = maxi | (1<<i);
                        node = node->get(1-bit);
                    }
                    else
                    {
                        node = node->get(bit);
                    }
                }
                return maxi;
                
        }
    };


    int maximumXor(vector<int> A)
    {
    Trie t;
    for(auto it:A){
        t.insert(it);
    }
    int maxi = 0;
    for(auto it:A){
        maxi = max(maxi,t.getmax(it));
    }

    return maxi;
    }


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> ans;
    int n = queries.size();
    Trie t;
    for(auto it:arr){
        t.insert(it);
    }
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for(auto it:arr){
            if(it<=queries[i][1]) maxi = max(maxi,t.getmax(it));
            else { maxi =-1;}
        }
        ans.push_back(maxi);
    }

    return ans;
    
}