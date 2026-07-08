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

vll topo_sort(const vector<vll>& g){
    vll indeg(sz(g)), q, nx_q, b(sz(g));
    for ( auto& li : g) for (int x : li) indeg[x]++;
    forn(i, 0, sz(g)) if (indeg[i] == 0) nx_q.push_back(i);
    ll cnt = 0;
    while(!nx_q.empty()){
        swap(q, nx_q);
        nx_q.clear();
        cnt++;
        forn(j, 0, sz(q)){
            b[q[j]] = cnt;
            for(int x : g[q[j]]) if(--indeg[x] == 0) nx_q.push_back(x);
        }
    }

    return b;
}

int main() {
    _; ll n; cin >> n;
    vll a(n);
    forn(i, 0, n) cin >> a[i];
    string s; cin >> s;
    vll rep(n);
    vector<vll> g(n);
    rep[0] = 0;

    forn(i, 0, n-1){
        if(s[i] == '=') rep[i+1] = rep[i];
        else rep[i+1] = i+1;

        if(s[i] == '>') g[rep[i+1]].push_back(rep[i]);
        if(s[i] == '<') g[rep[i]].push_back(rep[i+1]);
    }

    auto b = topo_sort(g);
    forn(i, 0, n) b[i] = b[rep[i]];

    ll sum = 0;
    forn(i, 0, n) sum += a[i]*b[i];
    cout << sum << ln;
    forn(i, 0, n) cout << b[i] << " \n"[i==n-1];
    return 0;
}
