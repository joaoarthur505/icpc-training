#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i = (s); i<(e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

# ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u << " = " u << ln)
#define debugv(v) trace(cout << #v << ": "; for(auto xx : v) cout << xx << " "; cout << ln;)

// const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _; ll n; cin >> n;
    vector<vll> sum(n, vll(n));
    vector<vector<bool>> game(n, vector<bool>(n));
    
    forn(i, 0, n)
    forn(j, 0, n){
        if(j >= i) game[i][j] = 0;
        else game[i][j] = (sum[i-1][j+1] == 0);

        sum[i][j] = (i > 0 ? sum[i-1][j] : 0) + game[i][j] - (i > j-1 ? game[i-j][j] : 0);
    }

    trace(
        forn(i, 0, n)
        forn(j, 0, n)
            cout << game[i][j] << " \n"[j==n-1];

        cout << ln;

        forn(i, 0, n)
        forn(j, 0, n)
            cout << sum[i][j] << " \n"[j==n-1];
    );

    if(game[n-1][0] == 0) cout << "Jane" << ln;
    else cout << "John" << ln;

    return 0;
}