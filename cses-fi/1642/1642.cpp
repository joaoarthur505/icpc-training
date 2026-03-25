#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    _; ll n, target; cin >> n >> target;

    map<ll, p64> idx;
    v64 v(n);
    forn(i, 0, n)cin >> v[i];

    if(n < 4){
        cout << "IMPOSSIBLE" << ln;
        return 0;
    }

    idx[v[0] + v[1]] = {0,1};

    forn(i, 2, n){
        forn(j, i+1, n){
            if(idx.count(target-v[i]-v[j])){
                auto p = idx[target-v[i]-v[j]];
                cout << p.first+1 << " " << p.second+1 << " " << i+1 << " " << j+1 << ln;
                return 0;
            }
        }

        forn(j, 0, i) idx[v[j] + v[i]] = {j, i};
    }

    cout << "IMPOSSIBLE" << ln;
    return 0;
}
