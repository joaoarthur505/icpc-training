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
 
// Modular Arithmetic Helpers
//
// Provides fast modular mul, fast exponentiation.
//
// complexity: O(log E) for power/inverse
 
 
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
        ld x = (ld)i / k;
        e -= pow(x, n);
    }
 
    ld resp = roundeven(e*1e6)/1e6;

    cout << fixed << setprecision(6) << resp << ln;
    return 0;
}