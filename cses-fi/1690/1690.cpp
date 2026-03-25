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
const ll MOD = 1000000007;

vector<vector<ll>> dp;
vector<v64> g;

ll summod(ll a, ll b){
    a += b;
    if(a >= MOD) a-= MOD;
    return a;
}

ll calc_dp(ll mask, ll ini){
    if(!(mask & (1<<ini))) return 0;
    debug(bitset<10>(mask).to_string());
    debug(ini);
    if(dp[mask][ini]!=-1) return dp[mask][ini];
    debug("peixe");
    if(mask == 1 && ini == 0) return 1;
    debug("peixe");
    if(!(mask&1)) return 0;

    ll sum = 0;
    for(auto j : g[ini]){
        debug(j);
        if(mask & (1<<j)){
            sum = summod(sum, calc_dp(mask^(1<<ini), j));
        }
    }

    return dp[mask][ini] = sum;
}

int main() {
    _; ll n, m; cin >> n >> m;
    g.resize(n);
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        g[b].push_back(a);
    }

    dp.resize(1<<n, v64(n, -1));

    cout << calc_dp((1<<n)-1, n-1) << ln;

    return 0;
}
  