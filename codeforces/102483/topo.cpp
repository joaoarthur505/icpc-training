#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

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

vll topo_sort_lib(const vector<vll>& g){
    ll n = sz(g);
    vll indeg(n), q;
    for(auto& li : g) for (ll x : li) indeg[x]++;
    forn(i,0,n) if (indeg[i] == 0) q.push_back(i);
    forn(j,0,sz(q)) for(ll x: g[q[j]]) if(--indeg[x] == 0) q.push_back(x);
}

// int main() {
//     _;
//     return 0;
// }
