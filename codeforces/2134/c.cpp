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
    ll b, c, d; cin >> b >> c >> d;
    ll a = 0;

    ll pot = 1;
    bool deu_ruim = false;
    while(d>0 || b>0){
        bool b_is_1 = b%2;
        bool c_is_1 = c%2;
        bool d_is_1 = d%2;

        if(d_is_1){
            if(!b_is_1 && c_is_1) deu_ruim = true;
            if(!c_is_1) a+=pot;
        }
        else{
            if(b_is_1 && !c_is_1) deu_ruim = true;
            if(b_is_1) a+=pot;
        }

        b/=2;
        c/=2;
        d/=2;
        pot*=2;
    }

    if(deu_ruim) cout << -1 << ln;
    else cout << a << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
