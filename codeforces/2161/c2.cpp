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
    ll n, x; cin >> n >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    sort(v.begin(), v.end());

    ll l = 0, r = n-1;
    ll curr_sum = 0;
    ll resp = 0;
    v64 order;
    while(l <= r){
        debug(l);
        debug(r);
        debug(curr_sum);
        if(curr_sum + v[r] >= x){
            resp += v[r];
            order.push_back(v[r]);
            curr_sum += v[r--];
            curr_sum %= x;
        } else {
            order.push_back(v[l]);
            curr_sum += v[l++];
        }
    }

    cout << resp << ln;
    for(auto y: order) cout << y << " ";
    cout << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
