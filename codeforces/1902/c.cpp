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

void solve(){
    ll n; cin >> n;
    v64 v(n);
    ll maximo = -INF;
    forn(i, 0,n){
        cin >> v[i];
        maximo = max(maximo, v[i]);
    }

    if(n == 1){
        cout << 1 << ln;
        return;
    }

    ll x = 0;
    forn(i, 0, n){
        x = gcd(x, maximo - v[i]);
        debug(maximo-v[i]);
    }

    ll sum = 0;
    set<ll> c;
    forn(i, 0, n){
        ll aux = (maximo-v[i])/x; 
        c.insert(aux);
        sum += aux;
    }

    ll falta = 0;
    while(c.count(falta)) falta++;
    sum += falta;
    cout << sum << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
