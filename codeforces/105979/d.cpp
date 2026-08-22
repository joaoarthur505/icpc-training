#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u)
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

struct dsu {
    vll id, len;

    dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }
    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    bool uni (ll a, ll b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if ( len[a] < len[b]) swap(a, b);
        len[a] += len[b], id[b] = a;
        return true;
    }
};

int main(){
    _; ll n, m; cin >> n >> m;
    vll v(n), ans(n);
    map<ll, vll> order;
    forn(i, 0, n){
        cin >> v[i];
        order[v[i]].push_back(i);
    }

    map<ll, vector<pll>> edges;

    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        ll power = max(v[a], v[b]);

        edges[power].push_back({a,b});
    }

    dsu sdu(n);

    for(auto &p : order){
        auto [power, vec] = p;

        if(edges.count(power)){
            for(auto e : edges[power]) sdu.uni(e.first, e.second);
        }

        for(auto vert : vec) ans[vert] = sdu.len[sdu.find(vert)]; 
    }

    forn(i, 0, n) cout << ans[i] << ln;
}


