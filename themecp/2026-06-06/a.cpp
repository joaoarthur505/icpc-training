#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

void solve(){
     ll n; cin >> n;
    vector<ld> dp(n+1, 0), c(n), alpha(n);
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        c[i] = a;
        alpha[i] = (1-((ld)b)/100);
    }

    for(ll i = n-1; i>= 0; i--){
        dp[i] = max(dp[i+1], c[i] + alpha[i]*dp[i+1]);
    }

    cout << fixed << setprecision(10) << dp[0] << ln; 
}

int main() {
    _; ll t; cin >> t; 
    while(t--) solve();
    return 0;
}
