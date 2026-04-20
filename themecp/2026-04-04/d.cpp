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

bool is_sqr(ll x){
    ll l = 1, r = x;
    while(l <= r){
        ll m = (l+r)/2;
        if((x%m == 0)  && (m == x/m)) return true;
        if(m > (x+(m-1))/m) r = m-1;
        else l = m+1;
    }
    return false;
}

void solve(){
    ll n; cin >> n;
    v64 a(n);
    forn(i, 0, n) cin >> a[i];

    ll best = 1;
    forn(i, 0, n)
    forn(j, i+1, n){
        ll k = a[j] - a[i];
        for(ll d = 1; d*d <= k; d++){
            if(k%d != 0) continue;
            if((d + k/d)%2 != 0) continue;

            ll count = 0;
            ll x = ((k/d - d)/2)*((k/d - d)/2) - a[i];
            if(x < 0) continue;

            debug(i);
            debug(j);
            debug(k);
            debug(d);
            debug(x);

            forn(l, 0, n){ 
                ll new_a = a[l] + x;
                if(is_sqr(new_a)) count++; 
            }

            best = max(best, count);
        }
    }

    cout << best << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
