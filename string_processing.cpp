#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<int> lps(const T &s, int n = 1){
  n = (int)s.size();
  vector<int> lps(n);
  int j = 0;
  for(int i = 1;i < n;i++){
    while(j > 0 && s[i] != s[j]) j = lps[j-1];
    if(s[i] == s[j]) j++;
    lps[i] = j;
  }
  return lps;
}

template <typename T>
vector<int> kmp(const T &s, const T &p){
  int n = (int)s.size(), m = (int)p.size();
  vector<int> lps = lps(p);
  vector<int> ans;
  int j = 0;
  for(int i = 0;i < n;i++){
    while(j > 0 && s[i] != p[j]) j = lps[j-1];
    if(s[i] == p[j]) j++;
    if(j == m){
      ans.push_back(i-j+1);
      j = lps[j-1];
    }
  }
  return ans;
}

template <typename T>
vector<int> z(const T &s, int n = 1){
  n = (int)s.size();
  vector<int> z(n);
  int L = 0, R = 0;
  for(int i = 1;i < n;i++){
    if(i < R) z[i] = min(R-i,z[i-L]);
    while(i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
    if(i + z[i] > R){
      L = i;
      R = i+z[i];
    }
  }
  return z;
}

struct Hash61 {
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t base;
  static vector<uint64_t> pw;
 
  uint64_t addmod(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t submod(uint64_t a, uint64_t b) const {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t mulmod(uint64_t a, uint64_t b) const {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }
 
  void ensure_pw(int sz) {
    int cur = (int) pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], base);
      }
    }
  }
 
  vector<uint64_t> pref, suff;
  int n;
 
  template<typename T>
  Hash61(const T& s) {
    n = (int) s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = addmod(mulmod(pref[i], base), s[i]);
    }
  }
 
  inline uint64_t operator()(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};

mt19937_64 rng61(chrono::steady_clock::now().time_since_epoch().count());
uint64_t Hash61::base = (md >> 2) + rng61() % (md >> 1);
vector<uint64_t> Hash61::pw = vector<uint64_t>(1, 1);