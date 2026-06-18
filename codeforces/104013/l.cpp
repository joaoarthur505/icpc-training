#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln endl

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

ll read(){
    ll a; cin >> a;
    return a-1;
}

void solve(){
    ll n; cin >> n;

    cout << "? ";
    forn(i, 2, n+1) cout << i << " ";
    cout << 1 << ln;

    vll cycle(n);
    forn(i, 0, n) cycle[i] = read();

    cout << "? ";
    cout << 1 << " ";
    forn(i, 3, n+1) cout << i << " ";
    cout << 2 << ln;

    vll fix(n);
    forn(i, 0, n) fix[i] = read();

    vll pi;
    forn(i, 0, n) if(i == fix[i]) pi.push_back(i);

    forn(i, 0, n) pi.push_back(cycle[pi.back()]);

    cout << "! ";
    forn(i, 0, n) cout << pi[i]+1 << " ";
    cout << ln; 

}

int main() {
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}
