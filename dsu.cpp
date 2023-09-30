struct DSU{
    vector<int> par, rnk, size;
    int c;
    DSU(int _n) : par(_n + 1), rnk(_n + 1, 0), size(_n + 1, 1), c(_n) {for (int i = 1; i <= _n; ++i) par[i] = i;}
    int find(int i){            //find parent of i
        return (par[i] == i ? i : (par[i] = find(par[i])));}
    bool same(int i, int j){    //check if i and j are in same component
        return find(i) == find(j);}
    int get_size(int i){        //size of component in which i is present
        return size[find(i)];}
    int count(){                //total components
        return c;}
    int merge(int i, int j){    //merge the components containing i and j and return the parent
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        size[j] += size[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;}
};