#include <bits/stdc++.h>
using namespace std;
struct Trie{
    static const int ALPHA = 26;    //Number of alphabets;
    static const char c = 'a';      //Starting alphabet;
    struct node{
        node* child[ALPHA];
        int start,stop;
        node(){
            for(int i = 0;i<ALPHA;i++) child[i] = NULL;
            start = stop = 0;
        }
    }*root;
    
    Trie(){
        root = new node();
    }
    void insert(string s){          //insert string into trie
        node* cur = root;
        for(int i = 0;i < sz(s);i++){
            if(!cur->child[s[i]-c]) cur->child[s[i]-c] = new node();
            cur->start++;
            cur = cur->child[s[i]-c];
        }
        cur->start++;
        cur->stop++;
    }
    bool search(string s){          //search if a string is present or not
        node* cur = root;
        for(int i = 0;i < sz(s);i++){
            if(!cur->child[s[i]-c]) return false;
            cur = cur->child[s[i]-c];
        }
        return cur->stop;
    }
    int count(string s){            //count how many words have prefix=s
        node* cur = root;
        for(int i = 0;i < sz(s);i++){
            if(!cur->child[s[i]-c]) return 0;
            cur = cur->child[s[i]-c];
        }
        return cur->start;
    }
    void dfs(node* cur){            //perform preorder dfs on trie
        for(int i = 0;i<ALPHA;i++){
            if(cur->child[i]){
                cout<<char(c+i);
                if(cur->child[i]->stop) cout<<"# ";
                else cout<<" ";
                dfs(cur->child[i]);
            }
        }
    }
    void del(string s){           //delete a word from trie
        if(!search(s)) return;
        node* cur = root;
        for(int i = 0;i < sz(s);i++){
            cur->start--;
            cur = cur->child[s[i]-c];
        }
        cur->start--;
        cur->stop--;
    }
};
/***************************************************************************************************/
struct BinTrie{
    static const int B = 31;
    struct node{
        node *nxt[2];
        int sz;
        node(){
            nxt[0] = nxt[1] = NULL;
            sz = 0;
        }
    } *root;
    BinTrie(){
        root = new node();
    }
    void insert(int val){
        node *cur = root;
        cur->sz++;
        for (int i = B - 1; i >= 0; i--){
            int b = val >> i & 1;
            if (cur->nxt[b] == NULL)
                cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->sz++;
        }
    }
    bool search(int val){
        node *cur = root;
        for (int i = B - 1; i >= 0; i--){
            int b = val >> i & 1;
            if (cur->nxt[b] == NULL) return false;
            cur = cur->nxt[b];
        }
        return true;
    }
    int query(int x, int k){ // number of values s.t. val ^ x < k
        node *cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--){
            if (cur == NULL) break;
            int b1 = x >> i & 1, b2 = k >> i & 1;
            if (b2 == 1){
                if (cur->nxt[b1])
                    ans += cur->nxt[b1]->sz;
                cur = cur->nxt[!b1];
            }
            else cur = cur->nxt[b1];
        }
        return ans;
    }
    int get_max(int x){ // returns maximum of val ^ x
        node *cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--){
            int k = x >> i & 1;
            if (cur->nxt[!k]) cur = cur->nxt[!k], ans <<= 1, ans++;
            else cur = cur->nxt[k], ans <<= 1;
        }
        return ans;
    }
    int get_min(int x){ // returns minimum of val ^ x
        node *cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--){
            int k = x >> i & 1;
            if (cur->nxt[k]) cur = cur->nxt[k], ans <<= 1;
            else cur = cur->nxt[!k], ans <<= 1, ans++;
        }
        return ans;
    }
    void del(node *cur){
        for (int i = 0; i < 2; i++) if (cur->nxt[i]) del(cur->nxt[i]);
        delete (cur);
    }
    void del(int val){
        if(!search(val)) return;
        node *cur = root;
        cur->sz--;
        for (int i = B - 1; i >= 0; i--){
            int b = val >> i & 1;
            if (cur->nxt[b] == NULL) return;
            else if(cur->nxt[b]->sz == 1){
                cur->nxt[b] = NULL;
                return;
            }
            cur = cur->nxt[b];
            cur->sz--;
        }
    }
};