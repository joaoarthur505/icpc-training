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
const ll MAX = 100'005;

vector<vll> divs(MAX);

vector<vll> create(vector<string>& mat, ll n, ll m, char c){
    vector<vll> dp(n, vll(m));
    forn(i,0,n) forn(j,0,m){
        // dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j] == c;
        dp[i][j] = (ll)(mat[i][j] == c);
        if(i > 0) dp[i][j] += dp[i-1][j];
        if(j > 0) dp[i][j] += dp[i][j-1];
        if(i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
    }
    debug(c);
    forn(i,0,n){debugv(dp[i]);}
    return dp;
}

void prep(){
    forn(i,1,MAX){
        for(ll j = i; j < MAX; j += i) divs[j].push_back(i);
    }
}

int main() {
    _;
    prep();

    ll n, m; cin >> n >> m;
    vector<string> mat(n);
    forn(i,0,n) cin >> mat[i];
    vector<vector<vll>> pref(5);
    pref[0] = create(mat, n, m, 'W');
    pref[1] = create(mat, n, m, 'A');
    pref[2] = create(mat, n, m, 'L');
    pref[3] = create(mat, n, m, 'D');
    pref[4] = create(mat, n, m, 'O');

    auto testa = [&](ll x, ll y, ll h, ll l, bool dbg){
        if(x + h >= n) return false;
        if(y + l >= m) return false;
        forn(t,0,5){
            ll sum = pref[t][x+h][y+l];
            if(x > 0) sum -= pref[t][x-1][y+l];
            if(y > 0) sum -= pref[t][x+h][y-1];
            if(x > 0 && y > 0) sum += pref[t][x-1][y-1];
            if(sum == 0) return false;
            if(dbg) cout << t << " " << sum << ln;
        }
        return true;
    };

    ll lef = 0;
    ll rig = n*m;
    ll ans = -1;

    while(lef <= rig){
        ll mid = (lef+rig)/2;
        bool bom = false;
        for(ll h: divs[mid]){
            ll l = mid/h; 
            trace(cout << l << " " << h << " " << mid << ln;)
            forn(i,0,n-h+1){
                forn(j,0,m-l+1){
                    if(testa(i,j,h-1,l-1, false)){
                        bom = true;
                        trace(cout << i << ":" << j << " " << h << ":" << l << ln;)
                        testa(i,j,h-1,l-1, true);
                    } 
                    if(bom) break;
                }
                if(bom) break;
            } 
            if(bom) break; 
        }
        if(bom){
            ans = mid;
            rig = mid-1;
        }else{
            lef = mid+1;
        }
    }
    cout << ans << ln;
    bool b = testa(0,3,5,4, true);
    debug(b);
    return 0;
}
