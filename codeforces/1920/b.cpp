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
    ll n, k, x; cin >> n >> k >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll curr_sum = 0;
    forn(i, 0, n){
        curr_sum += v[i];
        if(i >= n-x) curr_sum -= 2*v[i];
    }
    
    ll best_sum = curr_sum;
    forn(i, 1, k+1){
        curr_sum += v[n-i];
        if(n-i-x >= 0) curr_sum -= 2*v[n-x-i];

        best_sum = max(best_sum, curr_sum);
    }

    cout << best_sum << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i,0,t) solve();
    return 0;
}
