#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ll DINF = 1e18;

int main() {
    _; ll c, t, r; cin >> c >> t >> r;
    ld p; cin >> p;
 
    vector<ld> e(c+1);
    e[0] = 0;
    forn(i, 1, c+1){
        e[i] = e[i-1]/(1-p) + (1+p*r)/(1-p);
    }

    trace(
        forn(i, 0, c+1) cout << fixed << setprecision(20) << e[i] << ln;
    );

    vector<ld> dp(c+1, DINF);
    dp[c] = 0;
    for(ll i = c-1; i >= 0; i--){
        debug(i);
        forn(j, i+1, c+1) dp[i] = min(dp[i], e[j-i]+t+dp[j]);
    }

    cout << fixed << setprecision(20) << dp[0] << ln;
    return 0;
}
