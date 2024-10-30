struct SCC {

    int N;
    vector<vector<int>> adj, radj;
    vector<int> todo, comps, comp;
    vector<bool> vis;
    void init(int _N) {
        N = _N;
        adj.resize(N), radj.resize(N), comp = vector<int>(N, -1), vis.resize(N);
    }
    void add(int x, int y) { 
        adj[x].push_back(y), radj[y].push_back(x); 
    }
    void dfs(int x) {
        vis[x] = 1;
        for(auto y : adj[x]) if(!vis[y]) dfs(y);
        todo.push_back(x);
    }
    void dfs2(int x, int v) {
        comp[x] = v;
        for(auto y : radj[x]) if (comp[y] == -1) dfs2(y, v);
    }
    void gen(int _N) {  
        for(int i=1; i<=_N; i++) if (!vis[i]) dfs(i);
        reverse(begin(todo),end(todo));
        for(auto x: todo) if (comp[x] == -1) {
            dfs2(x, x);
            comps.push_back(x);
        }
    }
};
