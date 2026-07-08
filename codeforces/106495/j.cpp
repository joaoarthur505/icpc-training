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
const ll MOD = 1'000'000'007;

void solve(){
    ll n; cin >> n;
    ll p = n/2;
    ll imp = n - p;

    bool divided2 = false;
    bool divided3 = false;
    ll escolhe3 = 1;
    forn(i, 0, 3){
        ll mult = p-i;
        if(!divided2 && mult%2 == 0){
            divided2 = true;
            mult /= 2;
        }
        if(!divided3 && mult%3 == 0){
            divided3 = true;
            mult /= 3;
        }

        escolhe3 = (escolhe3*mult)%MOD;
    }

    divided2 = false;
    ll escolhe2 = 1;
    forn(i, 0, 2){
        ll mult = imp-i;
        if(!divided2 && mult%2 == 0){
            divided2 = true;
            mult /= 2;
        }

        escolhe2 = (escolhe2*mult)%MOD;
    }

    escolhe2 = (escolhe2*p)%MOD;

    cout << (escolhe2 + escolhe3)%MOD << ln; 
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
