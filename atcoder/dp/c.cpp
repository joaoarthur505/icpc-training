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

    ll n; cin >> n;
    vector<vll> atividades;
    atividades.push_back({0,0,0});

    forn(i,0,n){
        ll a,b,c;
        cin >> a >> b >> c;
        atividades.push_back({a,b,c});
    }

    vector<vll> dp(n+10);

    forn(i,0,3){
        dp[1][i] = atividades[1][i];
    }
    forn(i,2,n){
        ll a_ant = dp[i-1][0];
        ll b_ant = dp[i-1][1];
        ll c_ant = dp[i-1][2];

        dp[i][0] = a_ant + max(atividades[i][1],atividades[i][2]);
        dp[i][1] = b_ant + max(atividades[i][0],atividades[i][2]);
        dp[i][2] = c_ant + max(atividades[i][0],atividades[i][1]);

    }

    ll ans = max(max(dp[n][0],dp[n][1]),dp[n][2]);
    cout << ans;


    return 0;
}