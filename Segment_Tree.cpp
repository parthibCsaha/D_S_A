class SegmenTree {
public: 
    int N;
    vector<int> tree;
    SegmenTree(int n) {
        N = n;
        tree.resize(4*n, 0);
    }
    void update(int idx, int val, int l, int r, int v) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if(idx <= m) update(idx, val, l, m, 2*v);
        else update(idx, val, m + 1, r, 2*v + 1);
        tree[v] = max(tree[2*v], tree[2*v + 1]);
    }
    int query(int x, int y, int l, int r, int v) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        int m = (l + r) / 2;
        return query(x, y, l, m, 2*v) + query(x, y, m + 1, r, 2*v + 1);
    }
};
