        map<ll,ll> h,p;
        ll sm = 0,k = 19937;
        p[0] = 1;
        for(ll i=1;i<=n;i++) {
            p[i] = (p[i-1] * k) % mod;
            h[i] = (h[i-1] + (s[i-1]-'a'+1) * p[i]) % mod;
        }
