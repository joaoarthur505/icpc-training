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
const ll MAX = 500005;
const ll MOD = 1'000'000'007;

pair<vll, vll> sieve(ll n){
    vll lp(n+1);
    vll pr;
    forn(i, 2, n+1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    return {pr, lp};
}

void solve(vll &pr, vll &lp){
    ll n, x; cin >> n >> x;
    map<ll,ll> exp;
    forn(i, 0, n){
        ll a; cin >> a;
        while(a > 1){
            ll p = lp[a], alfa = 0;
            while(a%p == 0){
                alfa++;
                a /= p;
            }

            exp[p] += alfa;
        }
    }

    ll resp = 1;
    for(auto [p, e] : exp) resp = (resp*(e+1))%MOD;

    cout << resp << ln;
}

int main() {
    _; 
    auto [pr, lp] = sieve(MAX);
    ll t; cin >> t;
    while(t--) solve(pr, lp);
    return 0;
}
