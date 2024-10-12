#include <bits/stdc++.h>
using namespace std;

struct Median{
  multiset<int> l,r;
  // size of l is either equal to r or one more than r
  
  void balance(){
    if(l.size() < r.size()){
      int x = *r.begin();
      l.insert(x);
      r.erase(r.find(x));
    }
    if(l.size() > r.size()+1){
      int x = *l.rbegin();
      r.insert(x);
      l.erase(l.find(x));
    }
  }
  void insert(int x){
    if(l.empty()) l.insert(x);
    else if(x <= *l.rbegin()) l.insert(x);
    else r.insert(x);
    balance();
  }
  void remove(int x){
    if(r.find(x) != r.end()) r.erase(r.find(x));
    else l.erase(l.find(x));
    balance();
  }
  int getMedian(){
    int n = l.size() + r.size();
    if(n == 0) return -1;
    return *l.rbegin();
  }
};
/********************************  == ***********************************/
struct Mode{
  map<int,int> f;
  set<pair<int,int>> st;
  void insert(int x){
    if(st.find({f[x],x}) != st.end()){
      st.erase({f[x],x});
    }
    f[x]++;
    st.insert({f[x],x});
  }
  void remove(int x){
    if(st.find({f[x],x}) != st.end()){
      st.erase({f[x],x});
    }
    f[x]--;
    if(f[x]>0) st.insert({f[x],x});
  }
  int getMode(){
    if(st.empty()) return -1;
    return st.rbegin()->second;
  }
  int getMaxFreq(){
    if(st.empty()) return 0;
    return st.rbegin()->first;
  }
};