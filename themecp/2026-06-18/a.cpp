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

ll solve_count(ll n, ll mult){
    if(n == 1){
        return 1;
    }

    if(n%2 == 0){
        return solve_count(n/2, 2*mult) + 1;
    }

    return solve_count((n-1)/2, 2*mult) + 2;
}

void solve2(ll n, ll mult){
    if(n == 1){
        cout << 1*mult << " ";
        return;
    }

    if(n%2 == 0){
        solve2(n/2, 2*mult);
        cout << 1*mult << " ";
        return;
    }

    cout << n*mult << " ";
    solve2((n-1)/2, 2*mult);
    cout << 1*mult << " ";
}

void solve(){
    ll n; cin >> n;

    cout << solve_count(n, 1) << ln;
    solve2(n, 1);
    cout << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--)solve();
    return 0;
}
