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

void solve(){
    ll n, q; cin >> n >> q;
    vll v(n), acc(n), repeat(n, 0), repeat_acc(n);
    forn(i, 0, n){
        cin >> v[i];
        acc[i] = v[i] + (i == 0 ? 0 : acc[i-1]);

        if(i > 0 && v[i] == v[i-1]) repeat[i]++;
        repeat_acc[i] = repeat[i] + (i == 0 ? 0 : repeat_acc[i-1]);
    }

    function<ll (ll, ll)> zigzag = [&](ll b, ll a){
        return (repeat_acc[b] - repeat_acc[a]) == 0;
    };


    function<ll ()> query = [&](){
        ll a, b; cin >> a >> b;
        a--;
        b--;

        ll num_1 = acc[b] - (a == 0 ? 0 : acc[a-1]);
        ll num_0 = b-a+1 - num_1;

        if((num_1)%3 !=0 || (num_0)%3 != 0)return -1ll;

        ll resp = (b-a+1)/3 + zigzag(b, a);
        return resp;
    };

    while(q--) cout << query() << ln;
}

int main() {
    _;ll t; cin >> t;
    while(t--) solve();
    return 0;
}
