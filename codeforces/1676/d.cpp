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
    ll t; cin >> t;

    forn(i, 0, t) {

        ll nl, nc; cin >> nl; cin >> nc;

        vector<vector<ll>> linhas(nl, vector<ll>(nc));
        forn(y, 0, nl) {
            forn(x, 0, nc) cin >> linhas[y][x];
        }

        ll maximo = 0;
        forn(x0, 0, nc) forn(y0, 0, nl) {
            ll soma = linhas[y0][x0];

            ll x, y;
            
            x = x0; y = y0;
            while(--x >= 0 && --y >= 0) soma += linhas[y][x];
            
            x = x0; y = y0;
            while(++x < nc && --y >= 0) soma += linhas[y][x];
            
            x = x0; y = y0;
            while(--x >= 0 && ++y < nl) soma += linhas[y][x];
            
            x = x0; y = y0;
            while(++x < nc && ++y < nl) soma += linhas[y][x];

            if (soma > maximo) maximo = soma;
        }
        cout << maximo << ln;

    }

    return 0;
}
