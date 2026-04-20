#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
    _; ll n, a, b; cin >> n >> a >> b;
    vector<ld> prob(6*n + 1, 0), newprob(6*n+1, 0);
    prob[0] = 1;

    ld sixth = ((ld)1/(ld)6);

    forn(x, 0, n){
        forn(i, 0, 6*n+1){
            newprob[i] = 0;
            forn(j, 1, 7) if(i-j>=0){
                newprob[i] += sixth*(prob[i-j]);
                debug(prob[i-j]);
                debug(newprob[i]);
            }
        }
        debugv(prob);
        swap(prob, newprob);
    }

    ld p = 0;
    forn(i, a, b+1) p += prob[i];

    cout << fixed << setprecision(6) << p << ln;
    return 0;
}
