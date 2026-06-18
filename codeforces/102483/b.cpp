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
const ll INF = 100;
#define _
#else
#define trace(u)
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)


int main() {
    _;
    ll n; cin >> n;
    vll d(n);
    vector<vll> g(n);

    forn(i,0,n){
        cin >> d[i];
        ll k; cin >> k;
        forn(j,0,k){
            ll x; cin >> x;
            x--;
            g[x].push_back(i);
        }
    } 

    ll l = 0;
    ll r = 2*1'000'004;
    ll ans = r;
    
    auto testa = [&](ll maxt){
        debug(maxt);
        vll dp(n, INF);
        
        function<ll (ll)> dfs = [&](ll u){
            debug(u);
            ll resp = maxt-d[u];

            for(ll v: g[u]){
                if(dp[v] == INF) dfs(v);
                resp = min(resp, dp[v]-1);
            }

            return dp[u] = resp;
        };

        forn(i,0,n) {
            if(dp[i] == INF) dfs(i);
        }

        vll indeg(n);
        ll cnt = 0;
        priority_queue<pll> pq;

        for(auto& li : g) for (ll x : li) indeg[x]++;
        forn(i,0,n) if (indeg[i] == 0) pq.push({-dp[i], i});

        while(!pq.empty()){
            auto [k,v] = pq.top();
            pq.pop();
            if(d[v]+cnt > maxt) return false;
            cnt++;
            for(ll x: g[v]) if(--indeg[x] == 0) pq.push({-dp[x], x});
        }

        return true;
    };

    while(l <= r){
        ll m = (l+r)/2;
        if(testa(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << ans << ln;
    return 0;
}
