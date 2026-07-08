#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-9;

ll teto(ld x){
    ll floor = x;
    if(x - floor < eps) return floor;
    else return floor+1;
}

int main() {
    _; ll n, m; cin >> n >> m;
    ll sum1 = 0, sum2 = 0;
    forn(i, 0, n){
        ll a; cin >> a;
        sum1 += a;
    }
    forn(i, 0, m){
        ll a; cin >> a;
        sum2 += a;
    }

    if(teto((ld)sum1*(1.1)) <= sum2) cout << "YES" << ln;
    else cout << "NO" << ln;

    return 0;
}
