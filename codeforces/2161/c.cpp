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
    vector<ll> v(n);
    forn(i, 0, n) cin >> v[i];

    sort(v.begin(), v.end());

    ll l = 0, r= n-1;
    ll sum = 0;
    ll pts = 0;
    ll piso = 0;
    v64 order;

    while(l<=r){
        ll npiso = (sum + v[r])/x;
        if(npiso > piso){
            sum += v[r];
            pts += v[r];
            piso = npiso;
            order.push_back(v[r]);
            r--;
        } else {
            sum += v[l];
            order.push_back(v[l]);
            l++;
        }
    }

    cout << pts << ln;
    for(auto y : order) cout << y << " ";
    cout << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
