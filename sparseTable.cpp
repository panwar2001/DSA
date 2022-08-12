/*sparse table example for idempotent functions , here gcd is an idempotent function*/
class SparseTable
{
    int n, k;
    vector<vector<int>> st;
  public:
    SparseTable(vector<int> &v){
        n = v.size();
        k = (int)log2(n) + 1;
        st.resize(n, vector<int>(k + 1));
        for (int i = 0; i < n; i++)
          st[i][0] = v[i];
        for (int j = 1; j <= k; j++){
            for (int i = 0; i + (1 << j) <= n; i++){
                st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r){
        if (l == r)
            return st[l][0];
        int j = log2(r - l + 1);
        return __gcd(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
