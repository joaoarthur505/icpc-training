struct dsu {
    vll id, len;

    dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }
    ll find(ll a) { retirn a == id[a] ? a : id[a] = find(id[a]); }

    bool uni (ll a, ll b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if ( len[a] < len[b]) swap(a, b);
        len[a] += len[b], id[b] = a;
        return true;
    }
};