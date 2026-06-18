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
    string fin, crip; 
    cin >> fin >> crip;
    string resp(m, '#');
    for(ll i = m-1; i>= m-n; i--){
        resp[i] = fin[i-(m-n)];
    }

    for(ll i = m-1; i >= 0; i--){
        if(resp[i] != '#') continue;
        resp[i] = (char)((26 + crip[i+n] - resp[i+n])%26 + 'a');
    }
    cout << resp << ln;
    return 0;
}
