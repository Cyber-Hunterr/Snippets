template <typename T>
struct Matrix {
  int n,m;
  vector<vector<T>> v;
  Matrix() {}
  Matrix(int _n,int _m, bool Identity = false){
    n = _n; m = _m;
    v.assign(n,vector<T>(m,0));
    if(Identity){
      assert(n == m);
      for(int i = 0;i<n;i++) v[i][i] = 1;
    }
  }
  Matrix(vector<vector<T>> _v){
    n = _v.size();
    m = n ? _v[0].size() : 0;
    v = _v;
  }
  
  vector<T>& operator [] (int i){
    return this->v[i];
  }
  
  Matrix operator + (Matrix &b){
    assert(n == b.n && m == b.m);
    Matrix ans(n,m);
    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        ans[i][j] = v[i][j] + b[i][j];
      }
    }
    return ans;
  }
  Matrix operator - (Matrix &b){
    assert(n == b.n && m == b.m);
    Matrix ans(n,m);
    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        ans[i][j] = v[i][j] - b[i][j];
      }
    }
    return ans;
  }
  Matrix operator * (Matrix &b){
    assert(m == b.n);
    Matrix ans(n,b.m);
    for(int i = 0;i<n;i++){
      for(int j = 0;j<b.m;j++){
        for(int k = 0;k<m;k++){
          ans[i][j] += v[i][k] * b[k][j];
        }
      }
    }
    return ans;
  }
  Matrix operator ^ (long long k){
    assert(n == m);
    Matrix ans(n,m,true),t = *this;
    while(k){
      if(k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  Matrix & operator += (Matrix &b) { return *this = *this + b; }
  Matrix & operator -= (Matrix &b) { return *this = *this - b; }
  Matrix & operator *= (Matrix &b) { return *this = *this * b; }
  Matrix & operator ^= (long long k) { return *this = *this ^ k; }
  Matrix & operator == (Matrix &b) { return this->v == b.v; }
  Matrix & operator != (Matrix &b) { return this->v != b.v; }
};