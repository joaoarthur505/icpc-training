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
    string s; cin >> s;

    ll ini = 0;
    if(n%2 == 1){
        if(s[0] == 'b'){
            cout << "NO" << ln;
            return;
        }

        ini = 1;
    }

    while(ini < n){
        ll count_a = (s[ini] == 'a') + (s[ini+1] == 'a');
        ll count_b = (s[ini] == 'b') + (s[ini+1] == 'b');

        if(count_a == 2 || count_b == 2){
            cout << "NO" << ln;
            return;
        }

        ini += 2;
    }

    cout << "YES" << ln;
    return;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
