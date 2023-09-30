#include <bits/stdc++.h>
using namespace std;

/******************************************************************/
ll binpow(ll a, ll b, ll p = mod){
    ll res = 1;
    while (b > 0){
    if(b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b = b >> 1;
    }
    return res;
}
/******************************************************************/
ll add_m(ll a, ll b, ll m = mod) { a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod; }
ll sub_m(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return ((a - b) + m) % m; }
ll mul_m(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
/******************************************************************/
fact[0] = 1;
for (int i = 1; i < MAXN; i++)
{
    fact[i] = (1LL*fact[i - 1]*i)%mod;
}
/******************************************************************/
ll binpow(ll a, ll b, ll p = mod){
    ll res = 1;
    while (b > 0){
    if(b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b = b >> 1;
    }
    return res;
}
ll nCrModPFermat(ll n, ll r, ll p = mod){
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return (fact[n] * binpow(fact[r], p-2, p) %p* binpow(fact[n - r], p-2, p) % p) % p;
}
/******************************************************************/
template <const int MOD>
struct modint {
  int value;
  modint() = default;
  modint(int value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int c = (ll)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (ll)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(ull k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int MOD> modint<MOD> operator * (ll value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int MOD> modint<MOD> operator * (int value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;
/******************************************************************/
struct combi{
  int max_N; vector<mint> facts, finvs, invs;
  combi(int _n): max_N(_n), facts(_n), finvs(_n), invs(_n){
    facts[0] = finvs[0] = 1;
    invs[1] = 1;
    for (int i = 2; i < max_N; i++) invs[i] =  invs[mod % i] * (-mod / i);
    for(int i = 1; i < max_N; i++){
      facts[i] = facts[i - 1] * i;
      finvs[i] = finvs[i - 1] * invs[i];
    }
  }
  inline mint fact(int n) { return facts[n]; }
  inline mint finv(int n) { return finvs[n]; }
  inline mint inv(int n) { return invs[n]; }
  inline mint ncr(int n, int k) { return n < k or k < 0 ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};
combi C(MAXN);
/******************************************************************/