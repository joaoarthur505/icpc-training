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

void solve(){
    ll n, m; cin >> n >> m;
    debug(n);
    vector<bool> mark(n, false);
    vector<v64> g(n);

    forn(i, 0, m){
        ll a; cin >> a;
        a--;
        mark[a] = true;
    }
    forn(i, 0, n-1){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 up(n), down(n), resp(n);

    function<void (ll, ll)> dfs_down = [&](ll curr, ll parent) {
        for(auto v : g[curr]) if( v != parent) dfs_down(v, curr);

        down[curr] = mark[curr] ? 0 : -INF;

        for(auto v : g[curr]) if( v != parent) down[curr] = max(down[curr], down[v] + 1);
    };

    dfs_down(0, -1);

    debugv(down);

    up[0] = -INF;

    function<p64 (p64, ll)> update = [&](p64 p, ll x){
        if(x >= p.first) return p64(x, p.first);
        if(x >= p.second) return p64(p.first, x);
        return p;
    };

    function<void (ll, ll)> dfs_up = [&](ll curr, ll parent) {
        resp[curr] = max(up[curr], down[curr]);

        p64 best = {-INF, -INF};
        for(auto v : g[curr]) if( v != parent){
            up[v] = mark[curr] ? 1 : -INF;
            up[v] = max(up[v], up[curr] + 1);
            best = update(best, down[v]);
        }

        for(auto v : g[curr]) if( v != parent){
            ll best_for_v = best.first; 
            if(down[v] == best.first) best_for_v = best.second;
            up[v] = max(up[v], best_for_v + 2);
        }
        
        for(auto v : g[curr]) if( v != parent) dfs_up(v, curr);
    };

    dfs_up(0, -1);

    debugv(up);

    ll best = INF;
    forn(i, 0, n) best = min(resp[i], best);
    cout<< best << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
