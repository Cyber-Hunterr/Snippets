struct two_sat{
    int n;
    vector<vector<int>> g,rg;
    vector<int> comp,ans,vis;
    stack<int> stk;
    
    two_sat(int _n) : n(_n), g(2*_n), rg(2*_n), comp(2*_n), ans(_n), vis(2*_n) {}
    void add_edge(int u,int v){
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    
    void add_or(int u,bool f,int v,bool g){     //at least one is true - or
        add_edge(u + (f?n:0), v + (g?0:n));
        add_edge(v + (g?n:0), u + (f?0:n));
    }
    void add_xor(int u,bool f,int v,bool g){    //exactly one is true - xor
        add_or(u,f,v,g);
        add_or(u,!f,v,!g);
    }
    void add_and(int u,bool f,int v,bool g){    //both have have same value - xnor
        add_or(u,!f,v,g);
        add_or(u,f,v,!g);
    }
    
    void dfs(int u){
        vis[u] = 1;
        for(auto &v : g[u]){
            if(!vis[v]) dfs(v);
        }
        stk.push(u);
    }
    
    void scc(int u,int id){
        vis[u] = 1;
        comp[u] = id;
        for(auto &v : rg[u]){
            if(!vis[v]) scc(v,id);
        }
    }
    
    bool satisfiable(){
        for(auto &i:vis) i = 0;
        for(int i = 0;i<2*n;i++) if(!vis[i]) dfs(i);
        for(auto &i:vis) i = 0;
        int id = 0;
        while(!stk.empty()){
            int v = stk.top();stk.pop();
            if(!vis[v]) scc(v,id++);
        }
        
        for(int i = 0;i<n;i++){
            if(comp[i] == comp[i+n]) return false;
            ans[i] = comp[i] > comp[i+n];
        }
        return true;
    }
};