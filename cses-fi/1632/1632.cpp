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

bool cmp(p64 i1, p64 i2){
    if(i1.second != i2.second) return i1.second < i2.second;
    return i1.first < i2.second;
}

int main() {
    _; ll n, k; cin >> n >> k;
    vector<p64> inter(n);
    forn(i, 0, n) cin >> inter[i].first >> inter[i].second;

    sort(inter.begin(), inter.end(), cmp);

    multiset<ll> ends;
    forn(i, 0, k) ends.insert(0);

    ll counter = 0;
    forn(i, 0, n){
        trace(

        );
        auto curr = inter[i];
        auto it = ends.upper_bound(curr.first); // uma pessoa terminando o filme no tempo x pode comecar um filme comecando em x
        if(it == ends.begin()) continue;
        counter ++;
        it = prev(it);

        ends.erase(it);
        ends.insert(curr.second);
    }

    cout << counter << ln;

    return 0;
}
