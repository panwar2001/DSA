int cnt=0;
for(int i=1,t=sqrt(n);i<=t;i++){
            if(n%i==0){
                ans+=i;
                cnt++;
                if(n/i!=i)
                    cnt++;
            }
   }