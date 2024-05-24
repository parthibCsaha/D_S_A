void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        treee[node] = a[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        treee[node] = (treee[2*node] * treee[2*node+1]) ;
    }
}
void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        a[idx] += val;
        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start or end < l)
    {
        return 1;
    }
    if(l <= start and end <= r)
    {
        return treee[node] ;
    }
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 * p2) ;
}
