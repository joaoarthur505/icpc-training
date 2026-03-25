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
    v64 v(n);
    forn(i,0, n){
        cin >> v[i];
    }
 
    v64 acc_sum(n+1);
    acc_sum[0] = 0;
    forn(i, 1, n+1){
        acc_sum[i] = acc_sum[i-1]^v[i-1];
    }
 
    trace( 
        forn(i,0,n) cout << acc_sum[i] << ln;
    );
 
    forn(i, 0, k){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        debug(a);
        debug(b);
        ll x = acc_sum[b+1]^acc_sum[a];
        cout << x << ln;
    }
    return 0;
}