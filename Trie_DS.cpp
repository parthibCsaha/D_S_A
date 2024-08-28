// max xor subarray
class Triee {
public:
    ll N,cnt;
    vector<vector<ll>> trie;
    Triee(ll n) {
        N = n;
        cnt = 0;
        trie.resize(N*32, vector<ll>(2,0));
    }
    void insert(ll x) {
        ll node = 0;
        for(ll i=31;i>=0;i--) {
            ll bit = min(1ll,(1ll<<i)&x);
            if(!trie[node][bit]) {
                trie[node][bit] = ++cnt;
            }
            node = trie[node][bit]; 
        }
    }
    ll search(ll x) {
        ll node = 0,ans = 0;
        for(ll i=31;i>=0;i--) {
            ll bit = min(1ll,(1ll<<i)&x);
            if(trie[node][bit^1]) {
                ans |= 1ll<<i;
                node = trie[node][bit^1];
            }
            else {
                node = trie[node][bit];
            }
        }
        return ans;
    }
};
