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

int main() {
    _; ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i,0,n) cin >> v[i];
    vector<bool> win(n+1, false);
    win[0] = false;
    forn(i, 0, n+1){
        if(win[i]) continue;
        forn(j, 0, k){
            if(i + v[j] > n) continue;
            win[i + v[j]] = true;
        }
    }

    forn(i, 1, n+1){
        if(win[i]) cout << "W";
        else cout << "L";
    }

    cout << ln;
    return 0;
}
