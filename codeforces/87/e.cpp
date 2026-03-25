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

bool ccw(pt p, pt q, pt r, bool strict = true) { // true if p, q, r are 
    return sarea2(p, q, r) > 0 || (!strict && sarea2(p, q, r) == 0);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 && (a * b) <= 0;
}

vector<pt> minkowski(vector<pt> p, vector<pt> q) {
	auto fix = [](vector<pt>& P) {
		rotate(P.begin(), min_element(P.begin(), P.end()), P.end());
		P.push_back(P[0]), P.push_back(P[1]);
	};
	fix(p), fix(q);
	vector<pt> ret;
	int i = 0, j = 0;
	while (i < p.size()-2 or j < q.size()-2) {
		ret.push_back(p[i] + q[j]);
		auto c = ((p[i+1] - p[i]) ^ (q[j+1] - q[j]));
		if (c >= 0) i = min<int>(i+1, p.size()-2);
		if (c <= 0) j = min<int>(j+1, q.size()-2);
	}
	return ret;
}

// bool inpolygon(vector<pt> &p, pt a, bool strict = true) {
// 	ll cnt = 0, n = sz(p);
// 	forn(i,0,n) {
// 		pt q = p[(i + 1) % n];
// 		if (isinseg(a, line(p[i], q))) return !strict;
// 		cnt ^= (((a.y < p[i].y) - (a.y < q.y))*((p[i]-a)^(q-a))) > 0 ;
// 	}
// 	return cnt;
// }

bool inpolygonconv(vector<pt> &pol, pt p, bool strict = true) {
    if (pol.size() == 0) return false;
    if (pol.size() == 1) return (!strict && p == pol[0]);
    ll l = 1, r = pol.size();
    while (l < r) {
        ll m = (l+r)/2;
        if (ccw(p, pol[0], pol[m])) l = m+1;
        else r = m;
    }
    if (l == 1) return (!strict && isinseg(p, line(pol[0], pol[1])));
    if (l == pol.size()) return false;
    return !ccw(p, pol[l], pol[l-1], !strict);
}

int main() {
    _;
    ll a; 
    cin >> a;
    vector<pt> p1(a);
    forn(i, 0, a) cin >> p1[i];

    cin >> a;
    vector<pt> p2(a);
    forn(i, 0, a) cin >> p2[i];

    cin >> a;
    vector<pt> p3(a);
    forn(i, 0, a) cin >> p3[i];

    vector<pt> sum = minkowski(minkowski(p1, p2), p3);

    trace(
        forn(i, 0, sz(sum)) cout << sum[i].x << " " << sum[i].y << ln;
    );

    ll n; cin >> n;
    forn(i, 0, n){
        pt p; cin >> p;
        p = p*3;
        if(inpolygonconv(sum, p, false)){
            cout << "YES" << ln; 
        } else {
            cout << "NO" << ln;
        }
    }
    return 0;
}
