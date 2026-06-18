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

    ll resp = 0;
    forn(i, 0, n)
    forn(j, i+1, n+1){ // considerando a substring [i,j);
        debug(i); 
        debug(j);
        ll aux = i;
        ll cnt = 0;
        forn(k, i, j){
            debug(aux);
            if(s[k] == '1' && aux<=k){
                cnt++;
                aux = k+3;
            }
        }

        resp += cnt;
    }   

    cout << resp << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
