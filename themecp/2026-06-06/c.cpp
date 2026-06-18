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
const ll MAX = 47;

vll fibonacci(MAX);

void calc(){
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    forn(i, 2, MAX) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;

    while(n > 0){
        debug(x);
        debug(y);
        debug(n);
        if(y > fibonacci[n-1] && y <= fibonacci[n]){
            cout << "NO" << ln; 
            return;
        }

        if(y > fibonacci[n]) y-= fibonacci[n];
        n--;
        swap(x, y);
    }

    cout << "YES" << ln;
}

int main() {
    _;ll t; cin >> t;
    calc();
    while(t--) solve();
    return 0;
}
