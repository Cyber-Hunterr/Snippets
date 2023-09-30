bitset<MAXN> is_prime;
vector<int> lp(MAXN);

is_prime.set();
is_prime[0] = is_prime[1] = 0;
for (int i = 2; i < MAXN; i++)
{
    if(is_prime[i]){
        lp[i] = i;
        for (int j = 2*i; j < MAXN; j+=i)
        {
            is_prime[j] = 0;
            if(lp[j] == 0) lp[j] = i;
        }
    }
}