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
const ld eps = 1e-9;

ll cmp(ld x, ld y = 0, ld tol = eps){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
    _; ll n; cin >> n;
    vll c(n);
    forn(i, 0, n) cin >> c[i];
    sort(c.begin(), c.end());

    ld percent = 1;
    forn(i, 0, n){
        if(c[i] > i+1){
            cout << -1 << ln;
            return 0;
        }
 
        ld new_percent = (ld)c[i]/(i+1); 
        if(cmp(percent, new_percent) >= 0) percent = new_percent;
    }

    cout << fixed << setprecision(10) << percent << ln;

    return 0;
}
