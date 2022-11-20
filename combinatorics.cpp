class combinatorics{
    ll fact[1000001],p,inverse,m;
    ll inv(ll n){
      ll m=mod-2,inverse=1;
      while(m){
        if(m&1){
          inverse=inverse*n%p;
          m^=1;
        }else {
          n=n*n%p;
          m>>=1;
        }
      }
      return inverse;
    }
  public:
    combinatorics(ll p):p(p){
      fact[0]=1;
      for(int i=1;i<=1000000;i++)
        fact[i]=(fact[i-1]*i)%p;
     }
   inline ll C(ll n,ll r){
     return fact[n]*inv(fact[r])%p*inv(fact[n-r])%p;
    }
};
