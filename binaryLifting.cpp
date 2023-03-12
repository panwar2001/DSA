class DynamicTree{
 int l=25,n,d,d1,d2;
 vector<vector<int>>binaryLifting;
 vector<int>depth;
 pair<int,int>diameter={0,0};
 public:
  DynamicTree(int n){
    this->n=n;
    binaryLifting.resize(n+1,vector<int>(l,0));
    depth.resize(n+1,0);
  }
  int getLca(int a,int b){
     if(depth[a]>depth[b])
        swap(a,b);          
    for(int i=l;i>=0;i--){
        if(depth[a]+(1<<i)<=depth[b]){
            b=binaryLifting[b][i];
        }
    }
    if(a==b)return a;
    for(int i=l;i>=0;i--){
        if(binaryLifting[a][i]!=binaryLifting[b][i]){
            a=binaryLifting[a][i];
            b=binaryLifting[b][i];
        }
    }
    return binaryLifting[a][0];
  }
  int getDistance(int x,int y){
    return depth[x]+depth[y]-2*depth[getLca(x,y)];
  }
  void insert(int x,int y){
    binaryLifting[x][0]=y;
    for(int i=1;i<l;i++){
        if(binaryLifting[x][i-1]!=-1)
        binaryLifting[x][i]=binaryLifting[binaryLifting[x][i-1]][i-1];
    }
   depth[x]=depth[y]+1;
    d=getDistance(diameter.first,diameter.second);
   d1=getDistance(x,diameter.first);
   d2=getDistance(x,diameter.second);
   if(d1>=d&&d1>=d2)
    diameter.second=x;
   else if(d2>=d&&d2>=d1)
     diameter.first=x;
  }
  int getDiameter(){
     return getDistance(diameter.first,diameter.second);
  }
  int getkthAncestor(int a,int k){
    for(int i=l;i>=0;i--){
        if((1<<i)<=k){
            k-=1<<i;
            a=binaryLifting[a][i];
        }
    }
    if(a==0)return -1;
    return a;
  }
};
