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
    _;ll n, q; cin >> n >> q;
    ordered_set s;
    v64 sal(n);
    forn(i, 0, n){
        cin >> sal[i];
        s.insert({sal[i], i});
    }

    function<ll (ll, ll)> query = [&](ll l, ll r){
        ll vall = s.order_of_key({l, -1});
        ll valr = s.order_of_key({r, n});
        return valr - vall;
    };

    forn(i, 0, q){
        char c; cin >> c;
        if(c == '?'){
            ll l, r; cin >> l >> r;
            cout << query(l, r) << ln;
        } else {
            ll a, b; cin >> a >> b;
            a--;
            s.erase({sal[a], a});
            sal[a] = b;
            s.insert({sal[a], a});
        }
    }

    return 0;
}
