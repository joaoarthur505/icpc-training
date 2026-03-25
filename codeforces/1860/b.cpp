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
    ll m, k, a1, ak; cin >> m >> k >> a1 >> ak;
    ll q = m/k, r = m%k;
    if(r < a1){
        a1 -= r;
        ak += a1/k;
        cout << max(0ll, q-ak)<< ln;
        return;
    }

    cout << max(0ll, q-ak)+max(0ll, r-a1) << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i,0, t) solve();
    return 0;
}
