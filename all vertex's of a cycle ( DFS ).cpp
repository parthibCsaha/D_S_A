bool dfs(int v){
    used[v] = true;
    for (int u : g[v]){
        if (!used[u]){
            p[u] = v;
            if (dfs(u)) return true;
        }
        else if (p[v] != u){
            int w = v;
            while (w != u){
                cyc[w] = true;
                w = p[w];
            }
            cyc[w] = true;
            return true;
        }
    }
    return false;
}
