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

ll sarea2(pt p, pt q, pt r) { // 2 * signed area
    return (q-p)^(r-q);
}

ll polarea(vector<pt> v) { // area do poligono
	ll ret = 0;
	forn(i, 0, sz(v))
		ret += sarea2(pt(0, 0), v[i], v[(i + 1) % sz(v)]);
	return abs(ret);
}

int main() {
    _; ll n; cin >> n;
    vector<pt> poly(n);
    forn(i, 0, n) cin >> poly[i];
    ll s = polarea(poly);
    s += 2;

    ll border = 0;
    forn(i, 0, n){
        pt p = poly[(i+1)%n] - poly[i];
        border += gcd(p.x, p.y);
    }

    cout << (s - border)/2 << " " << border << ln;
    return 0;
}
