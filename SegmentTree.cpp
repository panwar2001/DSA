class SegmentTree{
  int n;  // array size
  vector<int>t;
public:
  SegmentTree(vector<int> &arr) {  // build the tree
    n=arr.size();
    t.resize(2*n,0);
    for(int i=0;i<n;i++)t[i+n]=arr[i];
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
};

class SegmentTree{
  vector<ll> segTree;
  int m;
  public:
    SegmentTree(int *a,int n):m(0){
       for(int i=0;i<n;i++){
        m=max(m,a[i]);
       }
       segTree.resize(2*m+2,0);
    }
    void updateSegTree(int pos){
      pos+=m+1;
      for(segTree[pos]+=1;pos>1;pos>>=1){
        segTree[pos>>1]=segTree[pos]+segTree[pos^1];
      }
    }
    ll getSum(int l,int r){
      ll sum=0;
        for(l+=m+1,r+=m+1;l<r;l>>=1,r>>=1){
           if(l&1){
            sum+=segTree[l++];
           }
           if(r&1){
            sum+=segTree[--r];
           }
        }
        return sum;
    }
};