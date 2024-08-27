class SegmenTree {
public: 
    ll N;
    vector<ll> tree;
    SegmenTree(ll n) {
        N = n;
        tree.resize(4*n, 0);
    }
    void update(ll idx, ll val, ll l, ll r, ll v) {
        if(l == r) {
            tree[v] = val;
            return;
        }
        ll m = (l + r) / 2;
        if(idx <= m) update(idx, val, l, m, 2*v);
        else update(idx, val, m + 1, r, 2*v + 1);
        tree[v] = max(tree[2*v], tree[2*v + 1]);
    }
    ll query(ll x, ll y, ll l, ll r, ll v) {
        if(r < x or l > y) return 0;
        if(l >= x and r <= y) return tree[v];
        ll m = (l + r) / 2;
        ll ans = max(query(x, y, l, m, 2*v),query(x, y, m + 1, r, 2*v + 1));
        return ans;
    }
};
