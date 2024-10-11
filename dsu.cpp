#include <bits/stdc++.h>
using namespace std;
struct DSU{
  int c;
  vector<int> par, size;
  DSU(int _n){
    c = _n;
    par.resize(_n + 1);
    size.assign(_n + 1, 1);
    iota(par.begin(), par.end(), 0);
  }
  int leader(int u){
    return u == par[u] ? u : par[u] = leader(par[u]);
  }
  bool same(int u,int v){
    return leader(u) == leader(v);
  }
  int get_size(int u){
    return size[leader(u)];
  }
  int count(){
    return c;
  }
  bool merge(int u,int v){
    if((u = leader(u)) == (v = leader(v))) return false;
    c--;
    if(size[u] < size[v]) swap(u,v);
    par[v] = u;
    size[u] += size[v];
    return true;
  }
};