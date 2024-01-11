const int LOG = 22;
void forward1(vl &dp){      //pull contribution from its subsets
    for(int bit = 0; bit < LOG; bit++)
        for(int i = 0; i < MAXN; i++)
            if(i&(1<<bit)) dp[i] += dp[i^(1<<bit)];
}
void backward1(vl &dp){
    for(int bit = 0; bit < LOG; bit++)
        for(int i = MAXN-1; i >= 0; i--)
            if(i&(1<<bit)) dp[i] -= dp[i^(1<<bit)];
}
void forward2(vl &dp){      //push contribution to its subsets
    for(int bit = 0;bit < LOG;bit++)
        for(int i = MAXN-1; i >= 0; i--)
            if(i&(1<<bit)) dp[i^(1<<bit)] += dp[i];
}
void backward2(vl &dp){
    for(int bit = 0;bit < LOG;bit++)
        for(int i = 0; i < MAXN; i++)
            if(i&(1<<bit)) dp[i^(1<<bit)] -= dp[i];
}