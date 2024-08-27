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
    void rangeupdate(ll l1, ll r1, ll val, ll l, ll r, ll v) {
        if(lazytree[v] != 0) {
            tree[v] += (r1 - l1 + 1) * lazytree[v];
            if(l1 != r1) {
                lazytree[2*v] += lazytree[v];
                lazytree[2*v+1] += lazytree[v];
            }
            lazytree[v] = 0;
        }
        if(r < l1 or l > r1) return;
        if(l1 >= l and r1 <= r) {
            tree[v] += (r1 - l1 + 1) * val;
            if(l1 != r1) {
                lazytree[2*v] += lazytree[v];
                lazytree[2*v+1] += lazytree[v];
            }
            return;
        }
        ll m = (l1 + r1) / 2;
        rangeupdate(l1, m, val, l, r, 2*v);
        rangeupdate(m + 1, r1, val, l, r, 2*v + 1);
        tree[v] = max(tree[2*v], tree[2*v + 1]);
    }
    ll query(ll l1, ll r1, ll l, ll r, ll v) {
        if(lazytree[v] != 0) {
            tree[v] += (r1 - l1 + 1) * lazytree[v];
            if(l1 != r1) {
                lazytree[2*v] += lazytree[v];
                lazytree[2*v+1] += lazytree[v];
            }
            lazytree[v] = 0;
        }
        if(r < l1 or l > r1) return 0;
        if(l1 >= l and r1 <= r) return tree[v];
        ll m = (l + r) / 2;
        ll ans = query(l1, m, l, r, 2*v)+query(m + 1, r, l, r, 2*v + 1);
        return ans;
    }
};
