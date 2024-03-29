template<class T, class U>
struct segtree{
    ll n; vector<T>st; T identity_element;
    // Definition of identity_element: the element I such that combine(x,I) = x

    segtree() {}
    segtree(ll n,T identity_element){
        init(n,identity_element);
    }
    void init(ll n, T identity_element){ this->n = n; this->identity_element = identity_element; st.assign(4*n,identity_element);}
    
    // Combine two nodes l and r.
    T combine(T l, T r){
        T ans = (l+r);	       // Sum
        // T ans = min(l,r);	   // Min
        // T ans = max(l,r);	   // Max
        return ans;
    }
    
    // Apply update upd to node curr.
    T apply(T curr, U upd){
        // T ans = upd;             	  // set to upd
        T ans = curr + upd;        // increment by upd
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a){
        if(tl == tr){
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    T queryUtil(ll v, ll tl, ll tr, ll l, ll r){
        if(l > r) return identity_element;
        if(tr < l or tl > r) return identity_element;
        if(l <= tl and r >= tr) return st[v];
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
    void updateUtil(ll v, ll tl, ll tr, ll pos, U upd){
        if(tl == tr){
            st[v] = apply(st[v],upd);
            return;
        }
        ll tm = (tl + tr)>>1;
        if(pos<= tm) updateUtil(2*v+1,tl,tm,pos,upd);
        else updateUtil(2*v+2,tm+1,tr,pos,upd);
        st[v] = combine(st[2*v + 1], st[2*v+2]);
    }

    void build(vector<T>a){
        assert( (ll)a.size() == n);
        buildUtil(0,0,n-1,a);
    }
    T query(ll l, ll r){
        return queryUtil(0,0,n-1,l,r);
    }
    void update(ll pos, U upd){
        updateUtil(0,0,n-1,pos,upd);
    }
};