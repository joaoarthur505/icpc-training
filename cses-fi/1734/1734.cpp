#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// Mo's Algorithm (Offline Range Queries)
//
// Answers offline range queries by ordering them (block or Hilbert curve) to get small pointer movement and amortized updates.
//
// complexity: O((N + Q) sqrt N), O(N)

const ll MAX = 2e5+10;
const ll SQ = sqrt(MAX);

inline void insert(ll p, ll &ans, v64 &freq, v64 &v) {
    debug("insert");
    debug(p);
    if(freq[v[p]] == 0) ans++;
    freq[v[p]]++;

    debug(ans);
}

inline void erase(ll p, ll &ans, v64 &freq, v64 &v) {
    debug("erase");
    debug(p);
    freq[v[p]]--;
    if(freq[v[p]] == 0) ans--;
}

inline ll hilbert(ll x, ll y) {
    static ll N = 1 << (__builtin_clzll(0ll) - __builtin_clzll(MAX));
    ll rx, ry, s;
    ll d = 0;
    for (s = N/2; s > 0; s /= 2) {
        rx = (x & s) > 0, ry = (y & s) > 0;
        d += s * ll(s) * ((3 * rx) ^ ry);
        if (ry == 0) {
            if (rx == 1) x = N-1 - x, y = N-1 - y;
            swap(x, y);
        }
    }
    return d;
}

#define HILBERT false
vector<ll> MO(vector<pair<ll, ll>> &q, vector<ll> &v) {
    v64 freq(sz(v));
    ll ans = 0;

    ll m = sz(q);
    vector<ll> ord(m);
    iota(ord.begin(), ord.end(), 0);
#if HILBERT
    vector<ll> h(m);
    for (ll i = 0; i < m; i++) h[i] = hilbert(q[i].first, q[i].second);
    sort(ord.begin(), ord.end(), [&](ll l, ll r) { return h[l] < h[r]; });
#else
    sort(ord.begin(), ord.end(), [&](ll l, ll r) {
        if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
        if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
        return q[l].second < q[r].second;
    });
#endif
    vector<ll> ret(m);
    ll l = 0, r = -1;

    for (ll i : ord) {
        ll ql, qr;
        tie(ql, qr) = q[i];
        while (r < qr) insert(++r, ans, freq, v);
        while (l > ql) insert(--l, ans, freq, v);
        while (l < ql) erase(l++, ans, freq, v);
        while (r > qr) erase(r--, ans, freq, v);
        ret[i] = ans;
    }
    return ret;
}

int main() {
    _;ll n, q; cin >> n >> q;
    v64 v(n), comp;
    forn(i, 0, n){
        cin >> v[i];
        comp.push_back(v[i]);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
 
    function<ll (ll)> trad = [&](ll x){
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    };

    forn(i, 0, n) v[i] = trad(v[i]);

    vector<p64> qu(q);
    forn(i, 0, q){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        qu[i]={a,b};
    }

    auto resp = MO(qu, v);
    forn(i, 0, q) cout << resp[i] << ln;
    return 0;
}
