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
    ll n, m; cin >> n >> m;
    vector<vll> a_inv(n, vll(m)), b(n, vll(m));
    vll min_row(n, INF);

    forn(i, 0, n)
    forn(j, 0, m){
        ll aux; cin >> aux; aux--;
        a_inv[aux/m][aux%m] = m*i+j;
    }

    forn(i, 0, n)
    forn(j, 0, m){
        ll aux; cin >> aux; aux--;
        b[i][j] = a_inv[aux/m][aux%m];
        min_row[i] = min(min_row[i], b[i][j]);
    }

    forn(i, 0, n)
    forn(j, 0, m){
        b[i][j]-=min_row[i];
    }

    forn(i, 0, n)
    forn(j, 0, m){
        if(b[i][j] != b[0][j]){
            cout << "NO" << ln;
            return;
        }
    }

    cout << "YES" << ln;
    return;

    trace(
        forn(i, 0, n)
        forn(j, 0, m){
            cout << b[i][j] << " \n"[j == m-1];
        }
    );
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
