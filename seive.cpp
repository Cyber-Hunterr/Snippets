for (int i = 2; i < MAXN; i++){
    if(lp[i] == 0){
        lp[i] = i;
        for (int j = 2*i; j < MAXN; j+=i)
        {
            if(lp[j] == 0) lp[j] = i;
        }
    }
}
vi lp(MAXN);