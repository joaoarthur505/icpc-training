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

int main() {
    _;
    ll n, m; cin >> n >> m;
    vector<string> mat(n);
    ll tot = 0;
    forn(i,0,n) cin >> mat[i];
    forn(i,0,n) forn(j,0,m) tot += (mat[i][j] == 'C');

    vector<vll> nxt(n, vll(m, m));
    vector<vll> vis(n, vll(m, 0));

    forn(i,0,n){
        for(ll j = m-2; j >= 0; j--){
            if(mat[i][j+1] == 'C') nxt[i][j] = j+1;
            else nxt[i][j] = nxt[i][j+1];
        }
    }

    forn(i,0,n){ debugv(nxt[i]);}

    ll cnt = 0;
    ll resp = 0;
    while (cnt < tot){
        resp++;
        ll x = 0;
        ll y = 0;
        while (y < n){
            if(!vis[y][x] && mat[y][x] == 'C'){
                cnt++;
                trace(cout << x << ":" << y << ln;)
                vis[y][x] = 1;
            }
            
            ll nx = nxt[y][x]; 
            if(nx >= m || vis[y][nx]){
                y++;
                continue;
            }
            x = nx;
        }
    }
    cout << resp << ln;
    return 0;
}
