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
 
int main() {
    _; ll n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    v64 v(n);
    v[0] = x;
    forn(i, 1, n) v[i] = (a*v[i-1] + b)%c;
 
    trace(
        forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    );
 
    ll sum_tot = 0;
    ll sum_curr = 0;
    forn(i, 0, k-1)sum_curr ^= v[i];
    debug(sum_curr);
    forn(i, k-1, n){
        sum_curr ^= v[i];
        debug(sum_curr);
        sum_tot ^= sum_curr;
        sum_curr ^= v[i-k+1];
    } 
 
    cout << sum_tot << ln;
    return 0;
}