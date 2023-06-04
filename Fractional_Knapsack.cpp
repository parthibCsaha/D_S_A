#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nl '\n'
void fractional_knapsack(ll w[],ll p[],ll idx[],float c[],ll k,ll n)
{
    float ans = 0;
    while(k) {
        ll max_idx = -1;
        float mc = 0.0;
        for(ll i=0;i<n;i++) {
            if(c[i]>mc && idx[i]==0) {
                mc = c[i];
                max_idx = i;
            }
        }
        idx[max_idx]++;
        for(ll i=0;i<n;i++) {
            if(i == max_idx) {
                if(w[i] <= k) {
                    ans += p[i];
                    k -= w[i];
                }
                else {
                    ans += k*c[i];
                    k -= k;
                }
            }
        }
    }
    cout << ans << nl;
}
int main()
{
    ll n;
    cin >> n;
    ll w[n],p[n],idx[n];
    for(ll i=0;i<n;i++) idx[i] = 0;
    float c[n];
    for(ll i=0;i<n;i++) {
        float x,y;
        cin >> x >> y;
        w[i] = x;
        p[i] = y;
        c[i] = y/x;
    }
    ll k;
    cin >> k;
    fractional_knapsack(w,p,idx,c,k,n);
}