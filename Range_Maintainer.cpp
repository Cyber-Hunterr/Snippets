struct Range_Maintainer{
    set<pair<int,int>> st;
    
    void set_range(int l,int r){
        auto it = st.upper_bound({l,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= l){
                l = it->first;
                r = max(r,it->second);
                st.erase(it);
            }
        }
        
        it = st.upper_bound({r,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= r){
                r = it->second;
                l = min(l,it->first);
                st.erase(it);
            }
        }
        
        while(1){
            it = st.lower_bound({l,0});
            if(it == st.end() || it->first > r) break;    
            st.erase(it);
        }
        st.insert({l,r});
    }
    
    void clear_range(int l,int r){
        auto it = st.upper_bound({l,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= r){
                int l1 = it->first;
                int r1 = l-1;
                
                int l2 = r+1;
                int r2 = it->second;
                
                st.erase(it);
                if(l1<=r1) st.insert({l1,r1});
                if(l2<=r2) st.insert({l2,r2});
                return;
            }
            if(it->second >= l){
                int lo = it->first;
                int hi = l-1;
                st.erase(it);
                if(lo<=hi) st.insert({lo,hi});
            }
        }
        
        it = st.upper_bound({r,1e9});
        if(it != st.begin()){
            it--;
            if(it->second > r){
                int lo = r+1;
                int hi = it->second;
                st.erase(it);
                st.insert({lo,hi});
            }
        }
        while(1){
            it = st.lower_bound({l,0});
            if(it == st.end() || it->first > r) break;
            st.erase(it);
        }
    }
    
    void print(){
        cout<<'[';
        for(auto &it:st) cout<<'{'<<it.first<<", "<<it.second<<"},";
        cout <<']'<<nl;
    }
};