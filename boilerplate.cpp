/**
 *    Author:  Rohit Meena
 *    Created: 12.10.2024 01:22:43
 *    Link: https://github.com/Cyber-Hunterr/Snippets
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sortall(x) sort(all(x))
#define sz(x) (int)(x.size())
#define nl '\n'

#ifdef JAI_SHREE_KRISHNA
  #include <debug.h>
#else
  #define dbg(x...) 32
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vii;
typedef vector<pll> vll;

// Operator overloads
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

const ll mod = 1000000007;
const ld eps = 1e-9;
const ll inf = 1e18;
const int MAXN = 1e6 + 1;

/**************************** --- Add Global Variables & Functions --- ****************************/
string yes = "YES\n",no = "NO\n";
/**************************** ---------------------------------------- ****************************/

void precompute(){
  
}
void solve(){
  ${0}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifdef JAI_SHREE_KRISHNA
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
  #endif
  int tc=1;
  ${1}cin>>tc;
  precompute();
  for(int i = 1; i <= tc; i++){
    // cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}