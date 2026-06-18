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
    _; ll n, c, b; cin >> n >> c >> b;
    vll v(n, -1);
    forn(i, 0, b){
        ll a; cin >> a; a--;
        debug(a);
        v[a]=0;
    }

    for(ll i = n-1; i >= 0; i--){
        if(v[i] == 0) continue;
        if(c >= 2 && i > 0){
            c-=2;
            v[i] = 1;
            v[i-1] = 0;
        }
        else if(c >= 1 && i==0){
            v[i] = 1;
            c -= 1;
        }
        else{
            v[i] = 0;
        }
    }

    forn(i, 0, n) cout << v[i];
    cout << ln;
    return 0;
}
