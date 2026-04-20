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
    _; ll n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    v64 v(n);
    v[0] = x;
    forn(i, 1, n) v[i] = (a*v[i-1] + b)%c;

    trace(
        forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    );

    v64 next_min(n);
    for(ll i = n-1; i>=0; i--){
        ll aux = i+1;
        while(aux < n && v[aux] > v[i]) aux = next_min[aux];
        next_min[i] = aux; 
    }

    trace(
        forn(i, 0, n) cout << next_min[i] << " \n"[i==n-1];
    );

    ll tot = 0;
    ll curr_min = 0;
    forn(i, k-1, n){
        while(curr_min < i-k+1) curr_min++;
        while(next_min[curr_min] <= i) curr_min = next_min[curr_min];

        debug(curr_min); 
        tot ^= v[curr_min];
    }

    cout << tot << ln;

    return 0;
}
