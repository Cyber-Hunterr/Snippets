struct Range_and_cuts{
    set<pii> ranges;
    multiset<int> lengths;
    
    Range_and_cuts() {}
    Range_and_cuts(int l,int r){
        ranges.insert({l,r});
        lengths.insert(r-l);
    }
    void cut(int x){
        auto it = ranges.upper_bound({x,1e9});
        if(it == ranges.begin()) return;
        it--;
        int l = it->first, r = it->second;
        
        lengths.erase(lengths.find(r-l));
        ranges.erase(it);
        ranges.insert({l,x});
        lengths.insert(x-l);
        ranges.insert({x,r});
        lengths.insert(r-x);
    }
    int get(){
        return *lengths.rbegin();
    }
};