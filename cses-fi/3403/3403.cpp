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

int main() {
    _; ll n, m; cin >> n >> m;
    v64 a(n), b(m);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, m) cin >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll> (m+1, 0));
    vector<vector<p64>> bt(n+1, vector<p64> (m+1, {-1, -1}));

    forn(i, 1, n+1)
    forn(j, 1, m+1){
        if(dp[i][j] <= dp[i-1][j]){
            dp[i][j] = dp[i-1][j];
            bt[i][j] = {i-1, j};
        }
        if(dp[i][j] <= dp[i][j-1]){
            dp[i][j] = dp[i][j-1];
            bt[i][j] = {i, j-1};
        }
        if(a[i-1] == b[j-1] && dp[i][j] <= 1 + dp[i-1][j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
            bt[i][j] = {i-1, j-1};
        }
    }

    cout << dp[n][m] << ln;
    v64 ans;
    ll x = n, y = m;
    while(x != 0 && y != 0){
        auto [nx, ny] = bt[x][y];
        if(nx == x-1 && ny == y-1) ans.push_back(a[x-1]);
        x = nx;
        y = ny;
    }

    for(ll i = sz(ans)-1; i >= 0; i--) cout << ans[i] << " \n"[i == 0];

    return 0;
}
