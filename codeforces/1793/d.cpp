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

ll corrige(ll i, ll skip){ return (i >= skip) ? i+1 : i;}

bool test(ll skip, v64 a){
    debug(skip);
    ll n = sz(a)-1;
    ll last = gcd(a[corrige(0, skip)], a[corrige(1, skip)]);
    forn(i, 0, n) debug(corrige(i, skip));
    forn(i, 1, n){
        ll curr = gcd(a[corrige(i, skip)], a[corrige(i-1, skip)]);
        if(curr < last) return false;
        last = curr;
    }

    return true;
}

void solve(){ 
    ll n; cin >> n;
    debug(n);
    
    v64 a(n);
    forn(i, 0, n){
        cin >> a[i];
    }
    
    if(n <= 3){
        cout << "YES" << ln;
        return;
    }

    ll last = gcd(a[0], a[1]);
    bool deu_bom = true;
    forn(i, 2, n){ 
        ll curr = gcd(a[i-1], a[i]);
        if(curr < last){
            deu_bom = test(i-2, a) || test(i-1, a) || test (i, a);
            break;
        }
        last = curr;
    }

    if(deu_bom){
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
