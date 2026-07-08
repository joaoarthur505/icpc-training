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
const ll MAXN = 50;

void solve(){
    ll n; cin >> n;
    vll tot(MAXN, 0);
    vector<vll> v(n, vll(50, 0));

    forn(i, 0, n){
        ll k; cin >> k;
        forn(j, 0, k){
            ll a; cin >> a; a--;
            tot[a]++;
            v[i][a]++;
        }
    }

    ll elem_tot = 0;
    forn(i, 0, MAXN) if(tot[i] > 0) elem_tot++;

    ll best = 0;
    forn(i, 0, n){
        ll elem = 0;
        forn(j, 0, MAXN){
            if(tot[j] == 0)continue;
            if(tot[j] == v[i][j]) continue;
            elem++;
        }

        if(elem == elem_tot) continue;
        best = max(elem, best);
    }

    cout << best << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
