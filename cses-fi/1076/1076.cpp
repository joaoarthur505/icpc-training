#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define ordered_set tree<p64, null_type,less<p64>, rb_tree_tag,tree_order_statistics_node_update> 

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// int main() {
//     ordered_set s;
//     s.find_by_order(position);
//     s.order_of_key(value);
// }


int main() {
    _; ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll ind_median = (k-1)/2;
    debug(ind_median);
    ordered_set s;
    forn(i, 0, k-1) s.insert({v[i], i});

    forn(i, k-1, n){
        s.insert({v[i], i});

        trace(
            cout << ln;
            debug(i);
            for(auto y: s) cout << y.first << " " << y.second << ln;
            cout << ln;
        );

        cout << s.find_by_order(ind_median)->first << " ";

        s.erase({v[i-(k-1)], i-(k-1)});
    }
    cout << ln;

    return 0;
}
