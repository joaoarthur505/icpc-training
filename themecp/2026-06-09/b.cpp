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

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vll color(n);
    ll height = 0;
    set<ll> used;

    forn(i, 0, n){
        if(s[i] == '(') height++;
        if(s[i] == ')') height--;

        if(height > 0 || (height == 0 && s[i] == ')')) color[i] = 1;
        if(height < 0 || (height == 0 && s[i] == '(')) color[i] = 2;
        used.insert(color[i]);
    }

    if(height != 0) cout << -1 << ln;
    else if(sz(used) == 1){
        cout << 1 << ln;
        forn(i, 0, n) cout << 1 << " \n"[i==n-1];
    }
    else{
        cout << sz(used) << ln;
        forn(i, 0, n) cout << color[i] << " \n"[i==n-1];
    }
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
