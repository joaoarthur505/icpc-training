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

v64 topo_sort(const vector<v64>& g) {
    v64 indeg(sz(g)), q;
    for (auto& li : g) for (int x : li) indeg[x]++;
    forn(i, 0, sz(g)) if (indeg[i] == 0) q.push_back(i);
    forn(j, 0, sz(q)) for(int x : g[q[j]]) if(--indeg[x] == 0) q.push_back(x);
    return q;
}


int main() {
    _; ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    v64 dp(n, 1), ord = topo_sort(g);

    for(auto u : ord)
    for()

    return 0;
}
