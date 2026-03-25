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

struct interval{
    ll x, y, idx;
    interval(ll _x, ll _y, ll _idx) : x(_x), y(_y), idx(_idx) {};
};

bool cmp(interval i1, interval i2){
    if(i1.x!=i2.x) return i1.x < i2.x;
    if(i1.y!=i2.y) return i1.y < i2.y;
    return i1.idx < i2.idx;
}

int main() {
    _; ll n; cin >> n;
    v64 room(n);
    set<p64> paciencia;
    vector<interval> inter;
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        inter.emplace_back(a,b,i);
    }

    sort(inter.begin(), inter.end(), cmp);
    trace(
        forn(i, 0, n){
            cout << inter[i].x << " " << inter[i].y << ln;
        }
    );

    ll color = 0;
    forn(i, 0, n){

        if(paciencia.empty() || (*paciencia.begin()).first >= inter[i].x) {
            paciencia.insert({inter[i].y, color});
            room[inter[i].idx] = color++;
        } else {
            auto p = paciencia.begin();
            auto aux = *p;

            paciencia.erase(p);
            paciencia.insert({inter[i].y, aux.second});
            room[inter[i].idx] = aux.second;
        }
    }

    cout << sz(paciencia) << ln;
    forn(i, 0, n) cout << room[i]+1 << " \n"[i == n-1];
    return 0;
}
