/*log₂(ba) time to calculte power , maximum b can be 2⁶⁴ ,therefore log₂2⁶⁴= 64 . 
* It takes theoritically  approx 64d(max) instructions to calculate power */
#define ll long long
ll pow(ll a, ll b,ll m){
  ll ans=1;
  while(b){
    if(b&1){
      ans*=a;
      ans%=m;
      b--;
    }
    else{
      a=(a*a)%m;
      b>>=1;
    }
  }
  return ans;
}
