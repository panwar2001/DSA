MATH FOR CP
//Divisors in O(root(n)) time
int cnt=0;
for(int i=1,t=sqrt(n);i<=t;i++){
            if(n%i==0){
                ans+=i;
                cnt++;
                if(n/i!=i)
                    cnt++;
            }
   }
//Divisors of a n numbers in O(n logn) time 
for(int i=1;i<=n;i++){
  for(int j=i;j<=n;j+=i){
    div[j]++; //i is a divisor of j
  }
}
_________________________________
Prime numbers in O(nlog(logn)) time using seive of eratosthenes

int prime[n];
vector<int>pr;
void seive(){
for(int i=2;i<n;i++){
   if(primes[i]==0){
    pr.push_back(i);
    for(int j=i*i;j<n;j+=i){
      primes[j]=1;
    }
}
primes[i]^=1;
}
_____________________________________________________________
int gcd(int a,int b){        //O(log(max(a,b)))
  if(a==0)return b;
  return gcd(b%a,a);// __gcd(a,b);
}
_____________________________________________________________

division under mod (multiplicative inverse)//fermats little theorum
(a/b)%m= (a* multiplicative_inverse(b)%m )% m = (a*((b^-1)%m))%m= (a* (pow(b,m-2)%m))%m 
m should be prime
can be used in combinatorics 
//HERE PRIME IS A MACRO FOR PRIME MODULO NUMBER 
int fact[n],invfact[n];
void init(){
  int p=PRIME;
  fact[0]=1;
  int i;
  for( i=1;i<n;i++)fact[i]=i*fact[i-1]%p;
  i--;
  invfact[i]=pow(fact[i],p-2,p);
  for(i--,i>=0;i--){
   // if(r>n||n<0||r<0)return 
   invfact[i]=infvact[i+1]*(i+1)%p;
  }
}
int ncr(int n,int r){
  if(r>n||n<0||r<0)return 0;
  return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}
__________________________________________________________________
xor formulas
a^b=a+b-(a&b)