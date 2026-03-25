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
    ll n; cin >> n;
    ll xini, yini, xfim, yfim; cin >> xini >> yini >> xfim >> yfim;
    v64 x(n);
    v64 y(n);
    forn(i, 0, n) cin >> x[i];
    forn(i, 0, n) cin >> y[i];

    map<ll,ll> down_mp, up_mp;
    forn(i, 0, n){
        if(!down_mp.count(x[i])) down_mp[x[i]] = y[i];
        else down_mp[x[i]] = min(y[i], down_mp[x[i]]);

        if(!up_mp.count(x[i])) up_mp[x[i]] = y[i];
        else up_mp[x[i]] = max(y[i], up_mp[x[i]]);
    }

    down_mp[xini] = yini;
    up_mp[xini] = yini;
    down_mp[xfim] = yfim;
    up_mp[xfim] = yfim;

    v64 down, up;
    for(auto [x_, y_] : down_mp) down.push_back(y_);
    for(auto [x_, y_] : up_mp) up.push_back(y_);

    n = sz(down);
    v64 dp_up(n, 0), dp_down(n, 0);

    for(ll i = n-2; i >= 0; i--){
        dp_up[i] = min(abs(up[i]-up[i+1]) + up[i+1] - down[i+1] + dp_down[i+1], abs(up[i]-down[i+1]) + up[i+1] - down[i+1] + dp_up[i+1]);
        dp_down[i] = min(abs(down[i]-up[i+1]) + up[i+1] - down[i+1] + dp_down[i+1], abs(down[i]-down[i+1]) + up[i+1] - down[i+1] + dp_up[i+1]);
    }

    cout << xfim - xini + min(dp_up[0], dp_down[0]) << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
