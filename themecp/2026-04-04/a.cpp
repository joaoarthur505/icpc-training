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

// Integer Geometry Primitives
//
// Defines 2D point and line structures with orientation, area, and angle comparisons plus a sweep-line comparator.

struct pt { // point
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x && y == p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ll c) const { return pt(x*c, y*c); }
    ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; } // dot product
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; } // cross product
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};

ll norm_sq(pt p){ return p*p;}

ll dist_sq(pt p, pt q){ return norm_sq(p - q);}

void solve() {
    ll n; cin >> n;
    vector<pt> v(n);
    forn(i, 0, n) cin >> v[i];
    pt ini, fim;
    cin >> ini >> fim;

    ll min_dist = INF;
    forn(i, 0, n) min_dist = min(min_dist, dist_sq(fim, v[i]));

    if(min_dist <= dist_sq(ini, fim)) cout << "NO" << ln;
    else cout << "YES" << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
