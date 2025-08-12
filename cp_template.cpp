
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <numeric>
#include <cassert>
// #define NDEBUG
#define nl " \n"
#define te cin >> t
#define ts to_string
#define pb push_back
#define pob pop_back
#define np next_permutation
#define rv reverse
#define inn insert
#define ff first
#define ss second
#define srt(x,y) sort((x),(x)+(y))
#define cnt(x,z) count(x.begin(),x.end(),z)
#define st for(int z=1;z<=t;z++)
#define ll long long int
#define lld long double
#define ull unsigned long long
#define cnt_bit(x) __builtin_popcount(x)
#define YES cout<<"YES"<<nl;
#define yes cout<<"Yes"<<nl;
#define NO cout<<"NO"<<nl;
#define no cout<<"No"<<nl;
#define cin1(x) scanf("%lld",&x);
#define cin2(x,y) scanf("%lld%lld",&x,&y);
#define cin3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
#define cout1(x) printf("%lld",x);
#define fori(x) for(ll i=0;i<(x);i++)
#define rofi(x) for(ll i=(x)-1;i>=0;i--)
#define forj(x) for(ll j=0;j<(x);j++)
#define rofj(x) for(ll j=(x)-1;j>=0;j--)
#define pi 2*acos(0.0)
#define mod(x) ((x)%N+N)%N
#define sz(x) x.size()
#define llu long long unsigned int
#define vect(type1,name) vector<type1>name
#define full(x) x.begin(),x.end()
#define cntt(x,y) count((x).begin(),(x).end(),(y))
#define amx  *max_element
#define amn  *min_element
#define gcd(x,y) (ll)(__gcd(x,y))
#define lcm(x,y) (ll)((x/gcd(x,y))*y)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less<ll>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
#define Flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef pair<ll,ll>pii;
typedef vector<char>vc;
typedef vector<ll>vi;
typedef vector<string>vs;
typedef map<ll,ll>mp;
typedef map<char,ll>mpc;
typedef map<string,ll>mps;
typedef set<ll>si;
typedef set<char>sc;
typedef deque<ll>dq;
typedef set<string>ss;
typedef vector<pair<ll,ll>>vp;
typedef unordered_set<ll>us;
typedef unordered_set<string>ust;
typedef multiset<ll>mst;
typedef multiset<string>mss;
typedef unordered_map<ll,ll>ump;
typedef unordered_map<string,ll>umps;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const ll N = 1e6;
const ll mod = 1e9+7;
ll maxi = 2147483647;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll fact[N];
// ll a[200005],treee[4*200005],m;

// void B_T_P(string& s,ll l,ll r) {
//     if(l==r){
//         cout << s << nl;
//         return;
//     }
//     else {
//         for(ll i=l;i<=r;i++) {
//             swap(s[l],s[i]);
//             B_T_P(s,l+1,r);
//             swap(s[l],s[i]);
//         }
//     }
// }
// string nthPermutation(const string& s,ll n) {
//    string news = s;
//    for(ll i=0;i<s.size();++i) {
//       sort(news.begin()+i,news.end());
//       if(n==0) break;
//       ll charPos = i+n/fact[s.size()-i-1];
//       swap(news[i], news[charPos]);
//       n = n%fact[s.size()-i-1];
//    }
//    return news;
// }
// void factorial()
// {
//     ll ff=1;
//     fact[0]=1;
//     for(ll i=1;i<=N;i++)
//     {
//         ff*=i;
//         // ff%=mod;
//         fact[i]=ff;
//     }
// }
// bool is_prime(ll x)
// {
//     if(x<2) return 0;
//     if(x==2) return 1;
//     if(x%2==0) return 0;
//     for(ll i=3;i*i<=x;i++)
//     {
//         if(x%i==0)return 0;
//     }
//     return 1;
// }
// void build(ll node, ll start, ll end)
// {
//     if(start == end)
//     {
//         treee[node] = a[start];
//     }
//     else
//     {
//         ll mid = (start + end) / 2;
//         build(2*node, start, mid);
//         build(2*node+1, mid+1, end);
//         treee[node] = (treee[2*node] * treee[2*node+1]) % m;
//     }
// }
// void update(ll node, ll start, ll end, ll idx, ll val)
// {
//     if(start == end)
//     {
//         a[idx] += val;
//         tree[node] += val;
//     }
//     else
//     {
//         ll mid = (start + end) / 2;
//         if(start <= idx and idx <= mid)
//         {
//             update(2*node, start, mid, idx, val);
//         }
//         else
//         {
//             update(2*node+1, mid+1, end, idx, val);
//         }
//         tree[node] = tree[2*node] + tree[2*node+1];
//     }
// }
// ll query(ll node, ll start, ll end, ll l, ll r)
// {
//     if(r < start or end < l)
//     {
//         return 1;
//     }
//     if(l <= start and end <= r)
//     {
//         return treee[node] % m;
//     }
//     ll mid = (start + end) / 2;
//     ll p1 = query(2*node, start, mid, l, r);
//     ll p2 = query(2*node+1, mid+1, end, l, r);
//     return (p1 * p2) % m;
// }
// class DSU {
//     vector<ll> rank, parent, size; 
// public: 
//     DSU(ll n) {
//         rank.resize(n+1, 0); 
//         parent.resize(n+1);
//         size.resize(n+1); 
//         for(ll i = 0;i<=n;i++) {
//             parent[i] = i; 
//             size[i] = 1; 
//         }
//     }
//     long long findPar(ll node) {
//         if(node == parent[node])
//             return node; 
//         return parent[node] = findPar(parent[node]); 
//     }
//     void unionByRank(ll u, ll v) {
//         ll ulp_u = findPar(u); 
//         ll ulp_v = findPar(v); 
//         if(ulp_u == ulp_v) return; 
//         if(rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v; 
//         }
//         else if(rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u; 
//         }
//         else {
//             parent[ulp_v] = ulp_u; 
//             rank[ulp_u]++; 
//         }
//     }
//     void unionBySize(ll u, ll v) {
//         ll ulp_u = findPar(u); 
//         ll ulp_v = findPar(v); 
//         if(ulp_u == ulp_v) return; 
//         if(size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v; 
//             size[ulp_v] += size[ulp_u]; 
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v]; 
//         }
//     }
// };
// ll spf[N];
// void seive()
// {
//     for(ll i=1;i<=N;i++){
//         spf[i] = i;
//     }
//     for(ll i=2;i<=N;i++){
//         if(spf[i]){
//             for(ll j=i*2;j<=N;j+=i){
//                  spf[j] = 0;
//             }
//         }
//     }
// }
// ll ncr(ll c[],ll n,ll r)
// {
//     for(ll i=1;i<=n;i++)
//     {
//         for(ll j=min(i,r);j>0;j--)
//         {
//             c[j]=(c[j]+c[j-1])%mod;
//         }
//     }
//     return c[r];
// }
// string alphabets="abcdefghijklmnopqrstuvwxyz";
// string digit="01";
// void creatstring(ll sz) {
//     srand(time(NULL));
//     string s;
//     for(ll i=0;i<sz;i++) {
//         s.push_back(alphabets[rand()%3]);
//     }
//     debug(s)
// }
// void creatarr(ll sz) {
//     srand(time(NULL));
//     vector<ll> v;
//     ll n = 10;
//     for(ll i=0;i<sz;i++) {
//         v.push_back(rand()%n);
//     }
//     debug(v)
// }
// void creatval(ll sz) {
//     srand(time(NULL));
//     cout << rand()%sz;
// }
// void dfs(ll i) 
// {
//     vis[i] = 1;
//     dfsvis[i] = 1;
//     for(auto &j:graph[i]) {
//         if(dfsvis[j]) cycle = 1;
//         else if(!vis[j]) dfs(j);
//     }
//     dfsvis[i] = 0;
// }
// ll exp_R(ll a,ll b,ll m)
// {
//     if(b==0)return 1;
//     ll res=exp_R(a,b/2,m);
//     if(b&1)
//         return (a*((res*1ll*res)%m)%m);
//     else
//         return (res*1ll*res)%m;
// }
// ll exp_I(ll a,ll b,ll m)
// {
//     ll ans=1;
//     while(b)
//     {
//         if(b&1)
//             ans=(ans*1ll*a)%m;
//         a=(a*1ll*a)%m;
//         b >>= 1;
//     }
//     return ans;
// }
void hello() {


}
int32_t main()
{
    Flash
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t; 
    // te;st
    hello();
    return 0;
}
