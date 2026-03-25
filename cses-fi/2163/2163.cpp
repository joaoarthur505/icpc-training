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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

const ll INF = 0x3f3f3f3f3f3f3f3fll;
int main() {
    _; ll n, k; cin >> n >> k;
    ordered_set s;
    forn(i, 0, n) s.insert(i);

    ll idx = 0;
    for(ll len = n; len > 0; len--){
        idx = (idx + k)%len;
        auto it = s.find_by_order(idx);
        cout << *it+1 << " \n"[len == 1];
        s.erase(it);
    }

    return 0;
}
