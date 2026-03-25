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

// Order-Statistic Tree (PBDS)
//
// Wraps __gnu_pbds tree to support order_of_key and find_by_order operations on a sorted set.
//
// complexity: O(log N) per op, O(N)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<p64, null_type,less<p64>, rb_tree_tag,tree_order_statistics_node_update> 

// int main() {
//     ordered_set s;
//     s.find_by_order(position);
//     s.order_of_key(value);
// }

int main() {
    _;
    ordered_set s;
    ll n; cin >> n;
    forn(i, 0, n){
        ll a; cin >> a;
        s.insert({i,a});
    }

    forn(k, 0, n){
        ll i; cin >> i; i--;
        auto it = s.find_by_order(i);
        cout << it->second << " \n"[k == n-1];
        s.erase(it);
    }

    return 0;
}
