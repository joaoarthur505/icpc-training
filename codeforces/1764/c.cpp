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
    map<ll,ll> freq;
    forn(i, 0, n){
        ll a; cin >> a; freq[a]++;
    }
    n = sz(freq);
    v64 v;
    for(auto [key, val] : freq) v.push_back(val);

    debug(n);

    if(n==1){
        cout << v[0]/2 << ln;
        return;
    }

    debugv(v);

    v64 prev_acc(n, 0), nxt_acc(n, 0);
    forn(i, 1, n) prev_acc[i] = prev_acc[i-1] + v[i-1];
    for(ll i = n-2; i >= 0; i--) nxt_acc[i] = nxt_acc[i+1] + v[i+1];
 
    ll best = v[0]*nxt_acc[0];
    forn(i, 1, n){
        if(nxt_acc[i] < prev_acc[i]) break;
        best -= v[i]*prev_acc[i];
        best += v[i]*nxt_acc[i];
    }
    cout << best << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
