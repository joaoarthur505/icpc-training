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
    _; ll n, t; cin >> n >> t;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll azul = 0;
    ll tempo_gasto = 0;
    ll best = 0;
    forn(preto, 0, n){
        while(azul < preto){
            tempo_gasto+=v[azul];
            azul++;
        }
        while(azul < n && tempo_gasto + v[azul] <= t){
            tempo_gasto+=v[azul];
            azul++;
        }

        if(tempo_gasto <= t) best = max(best, azul-preto);

        tempo_gasto -= v[preto];
    }

    cout << best << ln;
    return 0;
}
