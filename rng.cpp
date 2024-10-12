mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long a, long long b) { return uniform_int_distribution<long long>(a, b)(rng); }