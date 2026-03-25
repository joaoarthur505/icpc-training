#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 998244353;

void solve() {
    ll n, m; cin >> n >> m;
    v64 weight(n);
    vector<pair<ll,ll>> ord;
    forn(i, 0, n){
        cin >> weight[i];
        ord.push_back({-weight[i], i});
    }

    sort(ord.begin(), ord.end());

    vector<v64> g(n);
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    vector<map<ll, ll>> mp(n), mp2(n);

    forn(i, 0, n){
        ll u = ord[i].second;

        for(auto v : g[u]){
            mp[u][weight[v]] = (mp[u][weight[v]] + 1)%MOD;
            if(mp[v].count(weight[u] + weight[v])) mp[u][weight[v]] = (mp[u][weight[v]] + mp[v][weight[u] + weight[v]])%MOD;
        }
    }

    ll sum = 0;
    forn(i, 0, n){
        ll u = ord[i].second;

        for(auto v : g[u]){
            mp2[u][weight[v]] = 1;
            if(mp[v].count(weight[u] + weight[v])) mp2[u][weight[v]] = (mp2[u][weight[v]] + mp[v][weight[u] + weight[v]])%MOD;
            sum = (sum + mp2[u][weight[v]])%MOD;
        }
    }

    cout << sum << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}