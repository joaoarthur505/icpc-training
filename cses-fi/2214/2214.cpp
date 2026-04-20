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

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

// int main() {
//     ordered_set s;
//     s.find_by_order(position);
//     s.order_of_key(value);
// }

int main() {
    _; ll n, k;cin >> n >> k;
    
    v64 v(n); 
    set<ll> pick;
    forn(i, 0, n) pick.insert(i);
    ll decide = 0;
    while(k > (n-1)-decide){
        k -= (n-1)-decide;
        v[decide] = (n-1)-decide;
        pick.erase((n-1)-decide);
        decide++;
    }

    v[decide] = k;
    pick.erase(k);
    decide++;

    for(auto x : pick){
        v[decide] = x;
        decide++;
    }

    forn(i,0, n) cout << v[i]+1 << " ";
    cout << ln;

    return 0;
}
