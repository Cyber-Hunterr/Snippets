struct Str{
    int n;
    string s;
    Str() {};
    Str(string &s_){
        n = s_.length();
        s = s_;
    }
    vector<int> get_lps(){
        vector<int> lps(n);
        int i = 1, len = 0;
        while(i<n){
            if(s[i] == s[len]) lps[i++] = ++len;
            else if(len) len = lps[len-1];
            else i++;
        }
        return lps;
    }
    vector<int> get_z(){
        vector<int> z(n);
        int L = 0, R = 0;
        for(int i = 1;i<n;i++){
            if(i < R) z[i] = min(R-i,z[i-L]);
            while(i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
            if(i + z[i] > R){
                L = i;
                R = i+z[i];
            }
        }
        return z;
    }
    vector<int> search(string &p){
        int m = p.length();
        Str pat(p);
        vector<int> lps = pat.get_lps();
        vector<int> ans;
        int i = 0,j = 0;
        while(i<n){
            if(s[i] == p[j]) i++,j++;
            else if(j) j = lps[j-1];
            else i++;
            if(j == m){
                ans.push_back(i-j);
                j = lps[j-1];
            }
        }
        return ans;
    }
};