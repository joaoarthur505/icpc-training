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

map<string, ll> dic = {{"BR", 0}, {"BG", 1}, {"BY", 2}, {"GR", 3}, {"RY", 4}, {"GY", 5}};

bool intersect(ll i, ll j){
    if(i == j) return true;
    if(i > j) swap(i, j);
    p64 p = {i, j};
    if(p == p64{0, 5} || p == p64{1, 4} || p == p64{2, 3}) return false;
    return true;
}

void solve(){
    ll n, q; cin >> n >> q;
    vector<set<ll>> color(6);
    v64 v(n);
    forn(i, 0, n){
        string s; cin >> s;
        v[i] = dic[s];
        color[v[i]].insert(i);
    }

    forn(i, 0, q){
        ll a, b; cin >> a >> b;
        a--; b--;

        if(intersect(v[a], v[b])){
            cout << abs(a - b) << ln;
            continue;
        }

        if(a > b) swap(a, b);

        ll resp = INF;
        forn(c, 0, 6){
            if(c == v[a] || c == v[b]) continue;

            auto it = color[c].upper_bound(a);
            if(it != color[c].end())resp = min(resp, abs(*it - a) + abs(*it - b));
            if(it != color[c].begin()){
                it = prev(it);
                resp = min(resp, abs(*it - a) + abs(*it - b));
            }
        }

        if(resp == INF) cout << -1 << ln;
        else cout << resp << ln;
    }

}

int main() {
    _;ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
