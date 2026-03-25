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
const ll MAX = 8'000'000'000;
const ld eps = 1e-9;

int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void solve(){
    ll n; cin >> n; 
    v64 v(n); 
    vector<ld> log_v(n);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n) log_v[i] = log2(v[i]);

    if(n == 1){
        cout << 0 << ln;
        return;
    }

    ll resp = 0;
    ld curr_max = log_v[0];
    forn(i, 1, n){
        ld target = curr_max - log_v[i];

        debug(i);
        trace(
            cout << fixed << setprecision(10) << target << ln;
            cout << fixed << setprecision(10) << curr_max << ln;
            cout << fixed << setprecision(10) << log_v[i] << ln;
        );

        if(cmp(target, 0) <= 0)target = 0;
        ll target_int = target;
        if(cmp(target_int, target) != 0) target_int++;
        resp+= target_int;
        curr_max = target_int + log_v[i]; 

        debug(target_int);
        debug("\n");
    }
    
    cout << resp << ln;
}

int main() {
    _;
    ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
