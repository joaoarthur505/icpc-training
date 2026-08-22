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
    _; ll n, s1, s2; cin >> n >> s1 >> s2;
    vll v(n+1);
    forn(i, 0, s1){
        ll a; cin >> a;
        v[a] = i;
    }

    forn(i, 0, s2){
        ll a; cin >> a;
        v[a] = n-i;
    }

    ll especial = v[0];
    ll cnt = 0;

    vll next(n+1), prev(n+1);
    forn(i,0, n+1){
        next[i] = i+1;
        prev[i] = i-1;
    }

    auto del = [&](ll i){
        ll nx = next[i];
        ll pv = prev[i];

        if(nx == especial || pv == especial) cnt++;

        if(pv != -1) next[pv] = nx;
        if(nx != n+1) prev[nx] = pv;
    };

    forn(i, 1, n+1) del(v[i]);

    cout << cnt << ln;

    return 0;
}
