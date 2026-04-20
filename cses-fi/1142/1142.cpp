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
    _; ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    v64 last_small(n), next_small(n);
    ll best = 0;
    forn(i, 0, n){
        ll aux = i-1;
        while(aux >= 0 && v[i] <= v[aux]) aux = last_small[aux];
        last_small[i] = aux;
    }

    for(ll j = n-1; j>=0; j--){
        ll aux = j+1;
        while(aux < n && v[j] <= v[aux]) aux = next_small[aux];
        next_small[j] = aux;
    }

    forn(i, 0, n){
        best = max(best, v[i]*(next_small[i] - last_small[i] - 1));
    }

    cout << best << ln;
    return 0;
}
