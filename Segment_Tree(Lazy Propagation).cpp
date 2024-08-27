class LazySegmenTree {
public: 
    ll N;
    vector<ll> tree;
    vector<ll> lazytree;
    LazySegmenTree(ll n) {
        N = n;
        tree.resize(4*n, 0);
        lazytree.resize(4*n, 0);
    }
    void rangeupdate(ll low, ll high, ll val, ll l, ll r, ll v) {
        if(lazytree[v] != 0) {
            tree[v] += (high - low + 1) * lazytree[v];
            if(low != high) {
                lazytree[2*v] += lazytree[v];
                lazytree[2*v+1] += lazytree[v];
            }
            lazytree[v] = 0;
        }
        if(r < low or l > high) return;
        if(low >= l and high <= r) {
            tree[v] += (high - low + 1) * val;
            if(low != high) {
                lazytree[2*v] += val;
                lazytree[2*v+1] += val;
            }
            return;
        }
        ll m = (low + high) / 2;
        rangeupdate(low, m, val, l, r, 2*v);
        rangeupdate(m + 1, high, val, l, r, 2*v + 1);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
    ll query(ll low, ll high, ll l, ll r, ll v) {
        if(lazytree[v] != 0) {
            tree[v] += (high - low + 1) * lazytree[v];
            if(low != high) {
                lazytree[2*v] += lazytree[v];
                lazytree[2*v+1] += lazytree[v];
            }
            lazytree[v] = 0;
        }
        if(r < low or l > high) return 0;
        if(low >= l and high <= r) return tree[v];
        ll m = (low + high) / 2;
        return query(low, m, l, r, 2*v) + query(m + 1, high, l, r, 2*v + 1);
    }
};
