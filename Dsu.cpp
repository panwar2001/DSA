class DSU{
private:
  vector<int>weigh,parent;
public:
  DSU(int n){ //O(N) time & space complextiy for initialization of size and nodes.
    weigh.resize(n,1);
    parent.resize(n);
    for(int i=0;i<n;i++)
      parent[i]=i;
  } 
  inline int find(int x){
     if(parent[x]==x)
        return x;
      return parent[x]=find(parent[x]);
  }
inline bool Union(int a,int b){   //O(k) time complexity, here k<4 
     a=find(a);
     b=find(b);
     if(a==b) 
       return false;
     if(weigh[a]>weigh[b])
      swap(a,b);
     parent[a]=b;
     weigh[b]+=weigh[a];
     return true;
  }
};
