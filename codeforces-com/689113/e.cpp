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
const ll MAXN = 10000005;

pair<vll, vll> sieve(ll n){
    vll lp(n+1);
    vll pr;
    forn(i, 2, n+1) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(ll j = 0; i*pr[j] <= n; ++j) {
            lp[i*pr[j]] = pr[j];
            if(pr[j] == lp[i]) break;
        }
    }
    return {pr, lp};
}

int main() {
    _; ll n; cin >> n;
    auto [pr, lp] = sieve(MAXN);

    vll primes, primes2(1, 0);
    forn(i, 0, n){
        ll a; cin >> a;
        while(a != 1){
            primes.push_back(lp[a]);
            a /= lp[a];
        }
    }

    sort(primes.begin(), primes.end());

    ll curr_prime, ind = 0;
    while(ind < sz(primes)){
        curr_prime = primes[ind];
        ll aux = 0;
        while(ind < sz(primes) && primes[ind] == curr_prime){
            aux += curr_prime;
            ind++;
        }

        primes2.push_back(aux);
    }

    debugv(primes2);

    sort(primes2.rbegin(), primes2.rend());

    ll aux = 0;
    forn(i, 0, sz(primes2)){
        if(i %2 == 0) aux += primes2[i];
    }

    cout << aux << ln;
    return 0;
}
