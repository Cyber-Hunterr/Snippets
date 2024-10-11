void debug(int x) {cerr << x;}
void debug(long x) {cerr << x;}
void debug(long long x) {cerr << x;}
void debug(unsigned x) {cerr << x;}
void debug(unsigned long x) {cerr << x;}
void debug(unsigned long long x) {cerr << x;}
void debug(float x) {cerr << x;}
void debug(double x) {cerr << x;}
void debug(long double x) {cerr << x;}
void debug(char x) {cerr << '\'' << x << '\'';}
void debug(const char *x) {cerr << '\"' << x << '\"';}
void debug(const string &x) {cerr << '\"' << x << '\"';}
void debug(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>void debug(const pair<T, V> &x) {cerr << '{'; debug(x.first); cerr << ", "; debug(x.second); cerr << '}';}
template<typename T, typename V>void debug(const map<T, V> &x) {long long comma = 0; cerr << '['; for (auto &i: x) cerr << (comma++ ? ", " : ""), debug(i); cerr << "]";}
template<typename T, typename V>void debug(const unordered_map<T, V> &x) {long long comma = 0; cerr << '['; for (auto &i: x) cerr << (comma++ ? ", " : ""), debug(i); cerr << "]";}
template <typename ST>void debug(stack<ST> st) {long long comma = 0; cerr << "["; while (!st.empty()) { cerr << comma++ ? ", " : ""; debug(st.top()); st.pop(); } cerr << "]";}
template<typename Q> void debug(queue<Q> que) {long long comma = 0; cerr << "["; while (!que.empty()) { cerr << comma++ ? ", " : ""; debug(que.front()); que.pop(); } cerr << "]";}
template<typename Q> void debug(priority_queue<Q> pq) {long long comma = 0; cerr << "["; while (!pq.empty()) { cerr << comma++ ? ", " : ""; debug(pq.top()); pq.pop(); } cerr << "]";}
template<typename DQ> void debug(deque<DQ> dque) {long long comma = 0; cerr << "["; while (!dque.empty()) { cerr << comma++ ? ", " : ""; debug(dque.front()); dque.pop_front(); } cerr << "]";}
template<typename T>void debug(const T &x) {int comma = 0; cerr << '{'; for (auto &i: x) cerr << (comma++ ? ", " : ""), debug(i); cerr << "}";}
void dbg() {cerr << "]\n";}template <typename T, typename... V>void dbg(T t, V... v) {debug(t); if (sizeof...(v)) cerr << ", "; dbg(v...);}

#ifdef JAI_SHREE_KRISHNA
  #define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] =  ["; dbg(x); cerr  << endl;
#else
  #define dbg(x...) 32
#endif