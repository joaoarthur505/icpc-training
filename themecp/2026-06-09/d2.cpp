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

void solve(){
    ll n, m; cin >> n >> m;
    vector<vll> v(n, vll(m));
    forn(i, 0, n)
    forn(j, 0, m){
        cin >> v[i][j];
        v[i][j]--;
    }

    forn(i, 0, n){
        ll best_k = 0;
        forn(j, 0, n){
            ll k = 0;
            while(k <m && v[j][v[i][k]] == k) k++;

            best_k = max(best_k, k);
        }

        cout << best_k << " \n"[i == n-1];
    }
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
