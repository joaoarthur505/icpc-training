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

pll compare(pll p1, pll p2, ll k){
    ll v1 = p1.first, v2 = p2.first;
    ll v1_orig = v1, v2_orig = v2;

    ll pow = 1, x = 0;
    forn(i, 0, k) pow *= 2;

    forn(i, 0, k){
        pow /= 2;
        if(v1 < pow && v2 < pow) {
            x+= pow;
        }
        if(v1 >= pow) v1-=pow;
        if(v2 >= pow) v2-=pow;
    }

    return {(v1_orig^x)&(v2_orig^x), x};
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<pll> v(n);
    forn(i, 0, n){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    ll best_val = -1, best_i, best_j, best_x;
    forn(i, 0, n-1){
        auto [val, x] = compare(v[i], v[i+1], k);

        if(val > best_val){
            best_val = val;
            best_i = v[i].second;
            best_j = v[i+1].second;
            best_x = x;
        }
    }

    cout << best_i+1 << " " << best_j+1<< " " << best_x << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
