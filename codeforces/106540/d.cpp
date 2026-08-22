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

ld dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve(){
    ll x1, y1, r1; cin >> x1 >> y1 >> r1;
    ll x2, y2, r2; cin >> x2 >> y2 >> r2;
    ll k; cin >> k;

    if(r1 < r2){
        swap(r1, r2);
        swap(x1, x2);
        swap(y1, y2);
    }



    ld max_dist = 0;
    if(cmp(dist(x1, y1, x2, y2) + r2, r1) <= 0) max_dist = 2*r1;
    if(cmp(r1 + r2, dist(x1, y1, x2, y2)) <= 0) max_dist = 2*r1;

    if(max_dist == 0) max_dist = r1 + r2 + dist(x1, y1, x2, y2);

    trace(
        cout << fixed << setprecision(10) << max_dist << ln;
    ) 
    if(cmp(max_dist, k) >= 0) cout << "YES" << ln;
    else cout << "NO" << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
