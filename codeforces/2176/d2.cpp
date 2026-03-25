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

const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll dfs(ll u, ll target, vector<v64> &g, v64 &weight){
    ll sum = 0;
    for(auto w : g[u]){
        if(weight[w] == target){
            sum = (sum + 1 + dfs(w, weight[w]+weight[u], g, weight))%MOD;
        }
    }

    return sum;
}

int main(){
    _; ll t; cin >> t;

    ll n, m; cin >> n >> m;

    v64 weight(n);
    forn(i, 0, n){
        cin >> weight[i];
    }

    vector<v64> g(n);
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    ll sum = m;
    forn(i, 0, n){
        for(auto v : g[i]){
            sum = sum + dfs(v, weight[i] + weight[v], g, weight);
        }
    }

    cout << sum << ln;
    return 0;
}