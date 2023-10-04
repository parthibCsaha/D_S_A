class DisjointSet {
    vector<ll> rank, parent, size; 
public: 
    DisjointSet(ll n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(ll i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    long long findUPar(ll node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }
    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u); 
        ll ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u); 
        ll ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
