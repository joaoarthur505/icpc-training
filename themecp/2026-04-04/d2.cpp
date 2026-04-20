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
const ll MAXX = 10000;

bool is_sqr(ll x){
    ll l = 0, r = x;
    while(l <= r){
        ll m = (l+r)/2;
        if(m*m == x) return true;
        if(m*m > x) r = m-1;
        else l = m+1;
    }
    return false;
}

void solve(){
    ll n; cin >> n;
    v64 a(n);
    forn(i, 0, n) cin >> a[i];

    ll best = 0;
    forn(x, 0, MAXX){
        ll counter = 0;
        forn(i, 0, n) if(is_sqr(a[i]+x)) counter++;

        best = max(best, counter);
    }

    cout << best << ln;
}

int main() {
    ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
