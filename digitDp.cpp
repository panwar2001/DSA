/*fundamental structure of digit dp will remain same,only mask variable may change*/
class Solution {
  vector<int> num;
  int dp[11][2][1025];
  int len;
public:
int digitDp(int ind,bool prev,int mask){
          if(ind==len)
            return mask!=1;
          if(dp[ind][prev][mask]!=-1)
            return dp[ind][prev][mask];
          int ans=0,d=prev?num[ind]:9;
          for(int i=0;i<=d;i++){
              if(mask==1)mask=0;
              if((1<<i)&mask)continue; 
            ans+=digitDp(ind+1,min(d==i,prev),mask|(1<<i));
          }
          return dp[ind][prev][mask]=ans;
      }
    int numDupDigitsAtMostN(int n) {
         while(n){
          num.emplace_back(n%10);
          n/=10;
         }
         len=num.size();
         memset(dp,-1,sizeof dp);
         reverse(num.begin(),num.end());
          return digitDp(0,1,0);
  }
};