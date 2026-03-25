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
    v64 freq(n+1, 0);
    forn(i, 0, n){
        ll a; cin >> a;
        freq[a]++;
    }

    forn(i, 1, n+1){
        if(freq[i] == 1){
            cout << "No" << ln;
            return;
        }
        if(i == n){
            if(freq[i]%2 == 0) cout << "Yes" << ln;
            else cout << "No" << ln;
            return;
        }
        if(freq[i] == 0) continue;
        freq[i+1] += freq[i]-2;
    }
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
