void manacher() {
    string a;
    cin >> a;
    string s = "";
    s += '@';s += '#';
    for (auto i : a) s += i, s += '#';
    s += '$';
    a = s;
    ll n = a.size();
    ll mini[n] = {0};
    ll c = 0, r = 0, maxi = 0;
    for (ll i = 1; i < n; i++){
        ll mir = 2 * c - i;
        if (r > i){mini[i] = min(r - i, mini[mir]);
    }
    while (s[i - mini[i] - 1] == s[i + mini[i] + 1]){
        mini[i]++;
    }
    if (mini[i] + i > r){
        r = mini[i] + i;c = i;
    }
    maxi = max(maxi, mini[i]);
    }
    fori(n){
        if (mini[i] == maxi){
            string ans = "";
            for (ll j = i - mini[i]; j <= i + mini[i]; j++){
                if (s[j] != '#' && s[j] != '$' && s[j] != '@')ans += s[j];
            }
            cout << ans;
            return;
        }
    }
}