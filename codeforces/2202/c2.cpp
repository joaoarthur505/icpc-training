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

struct dsu {
    vector<ll> id, first_id;

    dsu(ll n) : id(n), first_id(n) { iota(id.begin(), id.end(), 0); iota(first_id.begin(), first_id.end(), 0);}

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        id[b] = a;
        first_id[b] = a;
    }
}; 


void solve(){
    ll n; cin >> n;
    v64 v(n);
    vector<p64> order;
    forn(i, 0, n){
        cin >> v[i];
        order.push_back({-v[i], i});
    }

    sort(order.begin(), order.end());

    dsu parent(n);
    for(auto [neg_val, idx] : order){
        ll val = -neg_val;
        debug(idx);
        if(idx == 0) continue;
        ll pai_ant = parent.find(idx-1);
        if(v[pai_ant] <= val-1 && val-1 <= v[idx-1]) parent.uni(pai_ant, idx);
    }

    
    ll sum = 0;
    forn(i, 0, n){
        ll nxt = n - i;
        ll prev = i - parent.first_id[i];
        if(i == parent.first_id[i]) prev = i+1;

        sum += prev*nxt;
    }

    cout << sum << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
