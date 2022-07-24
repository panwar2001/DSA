class BIT{
    vector<int> bit;
public:
    BIT(int n) : bit(n+1) { }
    void update(int i, int val) {
        for(; i <= size(bit); i += i & (-i)) bit[i] += val;
    }
    int query(int i) {  // returns number of elements in [0...i]
        int res = 0;
        for(; i > 0; i -= (i & (-i))) res += bit[i];
        return res;
    }
};