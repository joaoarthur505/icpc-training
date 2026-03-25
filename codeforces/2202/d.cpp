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

void solve_max(ll n){
    if(n == 1){
        cout << 1 << " " << 1 << " ";
        return;
    }
    v64 v(2*n);
    v[0] = 1;
    v[1] = 2;
    v[2*n-2] = n-1;
    v[2*n-1] = n;

    for(ll i = 1; 2*i+1<2*n-2; i+=1){
        v[2*i] = i+2;
        v[2*i+1] = i;
    }

    for(auto x: v) cout << x << " ";
}

void solve(){
    ll n, k; cin >> n >> k;
    if( k < n || k >= 2*n){
        cout << "NO" << ln;
        return;
    }
    ll a = k-n+1;
    cout << "YES" << ln;

    solve_max(a);

    forn(i, a+1, n+1) cout << i << " " << i << " ";
    cout << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
