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
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll l = 0, r = n-1, counter = 0;
    while(l < r){
        if(r-l == 1){
            counter += (v[l] == v[r]);
            break;
        }

        if(v[l+1] == v[r-1]) counter += (v[l+1] == v[l]) || (v[l+1] == v[r]);
        if(v[l] == v[r]) counter += (v[l] == v[l+1]) || (v[l] == v[r-1]);

        l++;
        r--;
    }

    cout << counter << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
