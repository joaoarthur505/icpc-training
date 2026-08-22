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
const ll MOD = 998244353;

vll pi(string& s){
    vll p(sz(s));
    for(ll i = 1, j = 0; i < sz(s); i++){
        while(j && s[j] != s[i]) j = p[j-1];
        if(s[j] == s[i]) j++;
        p[i] = j;
    }
    return p;
}

struct KMPaut : vector<vll> {
    KMPaut() {}
    KMPaut (string& s) : vector<vll>(26, vll(sz(s) + 1)) {
        vll p = pi(s);
        auto& aut = *this;
        aut[s[0]-'a'][0] = 1;
        for(char c = 0; c < 26; c++)
            for(int i = 1; i <= sz(s); i++)
                aut[c][i] = s[i] - 'a' == c ? i+1 : aut[c][p[i-1]];
    }
};

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vll> dp(k+1, vll(n+1, 0));
    dp[0][0] = 1;

    KMPaut kmp(s);
    vector<set<ll>> adj(n+1);

    forn(i, 0, 26)
    forn(j, 0, n+1){
        if(kmp[i][j] != 0) adj[j].insert(kmp[i][j]);
    }


    forn(i, 0, k){
        forn(j, 0, n+1){
            for(auto c : adj[j]) dp[i+1][c] = (dp[i+1][c] + dp[i][j])%MOD;
        }
    }

    ll resp = 0;
    forn(j, 0, n+1) resp = (resp + dp[k][j])%MOD;

    cout << resp << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
