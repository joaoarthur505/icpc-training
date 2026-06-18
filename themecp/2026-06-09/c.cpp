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

ll sqr_less(ll target){
    ll l = 1, r = sqrt(target) + 100, ans = 0;
    while(l <= r){
        ll m = (l+r)/2;
        if(m*m < target){
            ans = m;
            l = m + 1;
        } else {
            r = m -1;
        }
    }

    debug(target);
    debug(ans);

    return ans;
}

void solve(){
    ll r; cin >> r;
    ll resp = 4;
    forn(x, 1, r+1){
        ll delta = sqr_less((r+1)*(r+1) - x*x) - sqr_less(r*r - x*x); 
        resp = resp + 4*delta;
    }

    cout << resp << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
