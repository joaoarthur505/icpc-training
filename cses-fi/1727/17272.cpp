#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-9;
 
ll cmp(ld x, ld y = 0, ld tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
 
ld expo(ld b, ll e){
    ld ans = 1;
    for(; e; b = b*b, e /= 2)
        if(e & 1) ans = ans*b;
    return ans;
}
 
int main() {
    _; ll n, k; cin >> n >> k;
    ld e = k;
    forn(i, 0, k){
        e -= expo((ld)i/k, n);
    }

    ll aux = e*1e9;
    e = aux/1e9;
 
    ld aprox = e*10000000;
    debug(aprox);
    ll aprox_aprox = aprox;
    debug(aprox_aprox);
    bool round_up = false;
    if(aprox_aprox%10 == 5 && cmp(aprox_aprox, aprox) == 0) round_up = true;
    aprox_aprox /= 10;
    if(round_up && aprox_aprox %2 == 1) aprox_aprox++;
 
    cout << fixed << setprecision(6) << (ld)aprox_aprox/1000000 << ln;
    return 0;
}