#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#ifndef ONLINE_JUDGE
#include <algodebug>
#else
#define debug(...)
#endif
#define ll long long
//#define mod (ll)(1e9+7)
#define tc ll t;cin>>t;while(t--)
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool isPrime(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
bool checkSqrt(ll n){
  return (ll)sqrtl(n)*(ll)sqrtl(n)==n;
}
vector<int>primeNumbers;
void find(){
   int n=1000001;
  vector<int> seive(n,0);
  for(int i=2;i<=n;i++){
    for(int j=i<<1;j<=n;j+=i){
      seive[j]=1;
    }
    if(seive[i]==0){
      primeNumbers.push_back(i);
    }
  }
}
void solve(){
  ll num;
  cin>>num;
  ll f;
  ll divisors=1;
  for(ll i:primeNumbers){
    if(i*i*i>num){
      break;
    }
    f=1;
    while(num%i==0){
      num/=i;
      f++;
    }
    divisors*=f;
    if(num==1){
      break;
    }
  }
  if(num==1);
  else if(isPrime(num)){
    divisors<<=1;
  }else if(checkSqrt(num)&&isPrime(sqrtl(num))){
    divisors*=3;
  }else
  divisors<<=2;
  cout<<divisors<<endl;
}
int main() {
  find();
  fastio();
  tc
  solve();
}