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

bool consec(set<ll>& s){
    if(sz(s) > 2) return false;
    if(sz(s) <= 1) return true;
    ll a, b;
    a = *s.begin();
    b = *s.rbegin();
    return abs(a-b) == 1;
}

void solve(){ 
    ll n; cin >> n;
    set<ll> diag;
    set<ll> hori;
    set<ll> vert;
    set<ll> anti_diag;
    ll black = 0;
    forn(i, 0, n)
    forn(j, 0, n){
        char c; cin >> c;
        if(c == '#'){
            black ++;
            diag.insert(i-j);
            hori.insert(i);
            vert.insert(j);
            anti_diag.insert(i+j);
        }
    }

    bool deu_bom;
    if(black == 0) deu_bom = true;
    else if(black == 4){
        deu_bom = (consec(hori) && consec(vert)) || consec(diag) || consec(anti_diag);
    }
    else{
        deu_bom = consec(diag) || consec(anti_diag);
    }

    if(deu_bom) cout << "YES" << ln;
    else cout << "NO" << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
