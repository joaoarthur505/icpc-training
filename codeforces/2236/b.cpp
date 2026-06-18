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

char flip(char c){
    if(c == '0') return '1';
    else return '0';
}

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    forn(i, 0, n-k){
        if(s[i] == '1'){
            s[i] = flip(s[i]);
            s[i+k] = flip(s[i+k]);
        }
    }

    string zero(n, '0');

    if(zero == s) cout << "YES" << ln;
    else cout << "NO" << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
