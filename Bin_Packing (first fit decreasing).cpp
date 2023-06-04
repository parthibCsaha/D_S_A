#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nl '\n'
int main()
{
    ll n;
    cin >> n;
    ll a[n],idx[n];
    for(ll i=0;i<n;i++) cin >> a[i],idx[i] = 0;
    ll k,ans = 0,c,nn = n;
    cin >> k;
    sort(a,a+n,greater<ll>());
    while(n) {
        ll mc = k,c = 0;
        for(ll i=0;i<nn;i++) {
            if(a[i]<=mc && idx[i]==0) {
                mc -= a[i];
                idx[i]++;
                c++;
            }
        }
        n -= c;
        ans ++;
    }
    cout << ans << nl;
}