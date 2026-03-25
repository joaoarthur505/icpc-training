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
    ll n, k; cin >> n >> k;
    vector<v64> g(n);
    forn(i, 0, n-1){
        ll a, b; cin >> a >> b;
        a --;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll kawaiiness = n;

    function <ll (ll, ll)> dfs = [&](ll curr, ll parent){
        ll size = 0;
        for(auto v : g[curr]){
            if(v == parent) continue;
            ll size_filho = dfs(v, curr);
            if(size_filho <= n-k) kawaiiness += size_filho;
            size+=size_filho;
        }
        size++;

        if(size >= k) kawaiiness += n - (size);

        debug(curr);
        debug(size);
        return size;
    };
 
    dfs(0, -1);
    cout << kawaiiness << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
