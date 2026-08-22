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

// Modular Arithmetic Helpers
//
// Provides fast modular mul, fast exponentiation.
//
// complexity: O(log E) for power/inverse

typedef unsigned long long ull;

ull modmul(ull a, ull b, ull M){ 
    ll ret = a*b - M * ull(1.L / M*a*b);    
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
};

ull modpow(ull b, ull e, ull mod){
    ull ans = 1;
    for(; e; b = modmul(b, b, mod), e /= 2)
        if(e & 1) ans = modmul(ans, b, mod);
    return ans;
}


int main() {
    _;
    ll n, m, pri;
    cin >> n >> m >> pri;

    vll vis(n);
    vll cor(n, -1);
    vector<vll> g(n);
    
    forn(i,0,m){
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    function<bool (ll, ll)> dfs = [&](ll u, ll p){
        vis[u] = true;
        if(p != -1) cor[u] = cor[p]^1;
        else cor[u] = 0;

        for(ll v : g[u]){
            if(!vis[v]) dfs(v, u);
            if(cor[v] == cor[u]){
                return false;
            }
        }
        return true;
    };

    ll cnt = 0;
    forn(i,0,n) if(!vis[i]){
        bool b = dfs(i,-1);
        if(!b){
            cout << "impossible" << ln;
            return 0;
        }
        cnt++;
    };

    debug(cnt);
    cout << (modpow(2,cnt-1,pri)+1+pri)%pri << ln;
    return 0;
}
 