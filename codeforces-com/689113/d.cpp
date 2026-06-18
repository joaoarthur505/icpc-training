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

int main() {
    _; ll n, q; cin >> n >> q;
    string s; cin >> s;

    vll first_ap(26, INF);
    forn(i, 0, n){
        if(first_ap[s[i]-'a'] == INF) first_ap[s[i]-'a'] = i;
    }

    forn(i, 0, q){
        string t; cin >> t;

        vll first_diff(26, 0);
        ll ind = t[0]-'a';

        ll aux = 0;
        while(aux < sz(t) && t[aux] == t[0]) aux++;
        first_diff[ind] = aux;

        ll best = max(sz(s), sz(t));
        forn(j, 0, 26){
            best = max(best, sz(s) - first_ap[j] + sz(t) - first_diff[j]);
        }

        cout << best << ln;
    }

    return 0;
}
