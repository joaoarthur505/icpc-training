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
    _; ll n, q; cin >> n >> q;
    vector<v64> acc_tot(n+1, v64(n+1, 0));
    vector<v64> acc_row(n+1, v64(n+1, 0));

    forn(i, 1, n+1)
    forn(j, 1, n+1){
        char c; cin >> c;
        ll extra =( c == '*'); 
        acc_row[i][j] = acc_row[i][j-1]+extra;
        acc_tot[i][j] = acc_row[i][j] + acc_tot[i-1][j];
    }

    forn(i, 0, q){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        cout << acc_tot[x2][y2] - acc_tot[x1][y2] - acc_tot[x2][y1] + acc_tot[x1][y1] << ln;
    }
    return 0;
}
