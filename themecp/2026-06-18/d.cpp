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

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vll a(n), d(m), f(k);
    vector<pll> diff(n-1);

    forn(i, 0, n){
        cin >> a[i];
        if(i == 0) continue;
        
        diff[i-1] = {a[i] - a[i-1], i-1};
    }
    forn(i, 0, m) cin >> d[i];
    forn(i, 0, k) cin >> f[i];
    
    sort(diff.rbegin(), diff.rend());
    
    ll max_gap = 0, gap_ind, second_gap = 0;
    max_gap = diff[0].first;
    gap_ind = diff[0].second;

    if(n > 2 && diff[0].first == diff[1].first){
        cout << max_gap << ln;
        return;
    }

    if(n > 2) second_gap = diff[1].first;

    sort(d.begin(), d.end());
    sort(f.begin(), f.end());

    ll l = a[gap_ind], r = a[gap_ind+1];

    ll best_gap = INF;
    forn(i, 0, m){
        ll target = (l + r)/2 - d[i];
        ll ind = upper_bound(f.begin(), f.end(), target) - f.begin();

        forn(delta, -2, 3){
            if(ind + delta < 0 || ind + delta > k-1) continue;

            ll add = d[i] + f[ind + delta];

            if(add <= l || add >= r) continue;
            best_gap = min(best_gap, max(add - l, r- add));
        }
    }

    if(best_gap == INF){
        cout << max_gap << ln;
        return;
    }

    // cout << best_gap << ln;
    cout << max(best_gap, second_gap) << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
