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
const ll MAX = 2000000;
const ll BACK = 10;

map<ll,ll> dp;
v64 trig(MAX);

ll make_dp(ll a){
    debug(a);
    if(dp.count(a)) return dp[a];
    if(a == 0) return dp[a] = 0;

    ll best = INF;

    auto it = upper_bound(trig.begin(), trig.end(), a);
    forn(i, 0, BACK){
        if(it == trig.begin()) break;
        it = prev(it);

        best = min(best, make_dp(a-*it) + 1);
    }

    return dp[a] = best;
}

int main() {
    _;
    forn(i, 0, MAX) trig[i] = (i+1)*(i+2)/2;

    ll t; cin >> t;
    forn(i, 0, t){
        ll a; cin >> a;
        debug("peixe");
        debug(a);
        cout << make_dp(a) << ln;
    }

    return 0;
}
