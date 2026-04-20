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

v64 subtree;
vector<v64> g;

void dfs(ll curr){
    if(subtree[curr]!= -1) return;
    ll sum = 0;
    for(auto x : g[curr]){
        dfs(x);
        sum += subtree[x] + 1;
    }

    subtree[curr] = sum;
}

int main() {
    _; ll n; cin >> n;
    g.resize(n);
    subtree.resize(n, -1);
    forn(i, 1, n){
        ll a; cin >> a;
        a--;
        g[a].push_back(i);
    }

    forn(i, 0, n) dfs(i);

    forn(i, 0, n) cout << subtree[i] << " ";
    cout << ln;

    return 0;
}
