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

ll test(ll m, v64 &time){
    ll n = sz(time);
    ll sum = 0;
    forn(i, 0, n){
        sum += m/time[i];
    }
    return sum;
}

int main() {
    _; ll n, target; cin >> n >> target;
    v64 time(n);
    ll r = INF;
    forn(i, 0, n){
        cin >> time[i];
        r = min(time[i], r);
    }

    ll l = 0;
    r *= target;
    ll ans = r;
    while(l <= r){
        ll m = (l+r)/2;
        ll made = test(m, time);

        if(made >= target){
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << ln;
    return 0;
}
