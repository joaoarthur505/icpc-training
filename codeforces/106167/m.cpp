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
    _; ll d, s, e; cin >> d >> s >> e;
    if(s < d-s-e){
        cout << fixed << setprecision(10) << (double) ((d-s)*s)/(d*(d-s-e)) << ln;
        return 0;
    }

    cout << fixed << setprecision(10) << (double) (s+e)/(d) << ln;

    return 0;
}
