#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"
#define pb push_back

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll range = 1e7+2;

pair<vll, vll> sieve(ll n, vll &pr, vll &lp){
    lp.resize(n+1);
    forn(i, 2, n+1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    return {pr, lp};
}

int main() {
    ll n;

    vll pr, lp;
    sieve(range, pr, lp);

    while(cin >> n){
        cout << 1;
        while(n!=1){
            cout << " x " << lp[n];n/=lp[n];
        }
        cout << endl;
    }

    return 0;
}
