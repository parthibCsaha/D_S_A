template <typename T>
struct binary_indexed_tree {
    ll N;
    vector<T> BIT;
    binary_indexed_tree(ll N): N(N), BIT(N + 1, 0) {
    }
    void add(ll i, T x){
      i++;
      while (i <= N) {
        BIT[i] += x;
        i += i & -i;
      }
    }
    T sum(ll i) {
      T ans = 0;
      while (i > 0) {
        ans += BIT[i];
        i -= i & -i;
      }
      return ans;
    }
    T sum(ll L, ll R) {
      return sum(R) - sum(L);
    }
};
