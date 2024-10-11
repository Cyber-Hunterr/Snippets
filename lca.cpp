#include <bits/stdc++.h>
using namespace std;

struct LCA{
  const int LOG = 30;
  vector<vector<int>> par, adj;
  vector<int> sub,dep,tin,tout;
  int n,timer;
  
  LCA(int _n){
    n = _n+5;
    par.assign(n,vector<int>(LOG));
    adj.resize(n);
    sub.resize(n);
    dep.resize(n);
    tin.resize(n);
    tout.resize(n);
  }
  void add_edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int u,int p,int depth){
    sub[u] = 1;
    dep[u] = depth;
    par[u][0] = p;
    tin[u] = ++timer;
    for(auto &v:adj[u]) if(v!=p){
        dfs(v,u,depth+1);
        sub[u] += sub[u];
    }
    tout[u] = timer;
  }
  void root(int root,int def_p = 0){
    timer = -1;
    dfs(root,def_p,0);
    for(int d = 1;d < LOG;d++){
        for(int i = 0;i<n;i++){
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }
  }
  int go_up(int v,int k){
    if(k > dep[v]) return -1;
    for(int d = LOG-1 ;d>=0;d--){
        if(k & (1<<d)) v = par[v][d];
    }
    return v;
  }
  int get_lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    int k = dep[u]-dep[v];
    u = go_up(u,k);
    if(u==v) return u;
    for(int d = LOG-1;d>=0;d--){
        if(par[u][d] == par[v][d]) continue;
        u = par[u][d];
        v = par[v][d];
    }
    return par[u][0];
  }
  int get_dist(int u,int v){
    return dep[u]+dep[v]-2*dep[get_lca(u,v)];
  }
};