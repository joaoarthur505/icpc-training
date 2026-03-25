#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-9;

ll cmp(ld x, ld y = 0, ld tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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

struct line { // line segment
    pt p, q;

    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
    bool operator < (const line l) const {
        if (!(p == l.p)) return p < l.p;
        return q < l.q;
    }
    bool operator == (const line l) const {
        return p == l.p && q == l.q;
    }
    friend istream& operator >> (istream& in, line& r) {
        return in >> r.p >> r.q;
    }
};

ll sarea2(pt p, pt q, pt r) { // 2 * signed area
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) { // true if p, q, r are 
    return sarea2(p, q, r) > 0;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 && (a * b) <= 0;
}


bool inpolygon(vector<pt> &p, pt a, bool strict = true) {
	ll cnt = 0, n = sz(p);
	forn(i,0,n) {
		pt q = p[(i + 1) % n];
		if (isinseg(a, line(p[i], q))) return !strict;
		cnt ^= (((cmp(a.y, p[i].y) < 0) - (cmp(a.y,q.y) < 0))*((p[i]-a)^(q-a))) > 0 ;
	}
	return cnt;
}

int main() {
    _; ll n, q; cin >> n >> q;
    vector<pt> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }

    forn(i, 0, q){
        pt a; cin >> a;
        if(!inpolygon(v, a, false)){
            cout << "OUTSIDE" << ln;
            continue;
        }
        if(!inpolygon(v,a)){
            cout << "BOUNDARY" << ln;
            continue;
        }
        cout << "INSIDE" << ln;
    }
    return 0;
}
