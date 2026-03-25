#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld DINF = 1e18;
const ld eps = 1e-9;

int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (cmp(x, p.x) != 0) return cmp(x, p.x) < 0;
		if (cmp(y, p.y) != 0) return cmp(y, p.y) < 0;
		return 0;
	}
	bool operator == (const pt p) const {
		return cmp(x, p.x) == 0 and cmp(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
    friend ostream& operator << (ostream& out, pt& p) {
		return out << p.x << ", " << p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
}; 

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return cmp(sarea(p, q, r),0) > 0;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return cmp((a ^ b), 0) == 0 and cmp(a * b, 0) <= 0;
}

ld polarea(vector<pt> v) { // area do poligono
	ld ret = 0;
	for (int i = 0; i < sz(v); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % sz(v)]);
	return abs(ret);
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
    
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s) { // r inter s
	if (cmp((r.p - r.q) ^ (s.p - s.q), 0) == 0) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

vector<pt> poly;
ll n;

vector<pt> cut_polygon(vector<pt>& v, line r) { // O(n)
    // debug(r.p.x);
	vector<pt> ret;
    // debug(sz(v));
	for (int j = 0; j < sz(v); j++) {
        // debug(r.p);
        // debug(r.q);
        // debug(v[j]);
        // debug(ccw(r.p, r.q, v[j]));
		if (ccw(r.p, r.q, v[j]) || isinseg(v[j], r)) ret.push_back(v[j]);
		if (sz(v) == 1) continue;
		line s(v[j], v[(j+1)%sz(v)]);
        debug(s.p);
        debug(s.q);
		pt p = inter(r, s);
        debug(p);
		if (isinseg(p, s)) ret.push_back(p);
	}
    // debug(sz(ret));
	if (sz(ret) > 1 and ret.back() == ret[0]) ret.pop_back();
	return ret;
}

ld test(ld x){
    line vert = line(pt(x, -DINF), pt(x, DINF));
    vector<pt> cut = cut_polygon(poly, vert);

    trace(forn(i, 0, sz(cut)){
        debug(cut[i]);
    });

    return polarea(cut);
}

int main(){
    _; ll k; cin >> n >> k;
    poly.resize(n);
    ll min_x = INF, max_x = 0;

    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        poly[i] = pt(a,b);
        min_x = min(min_x, a);
        max_x = max(max_x, a);
    }

    ld s = polarea(poly);
    ld target = s/(k+1); 
    trace(cout << fixed << setprecision(10) << target << ln;);

    ll it = 10;
    ld l = min_x, r = max_x, m;
    forn(i, 0, it){
        m = (l+r)/2;

        ld ans = test(m);
        trace(cout << fixed << setprecision(10) << m << ln;);
        trace(cout << fixed << setprecision(10) << ans << ln;);

        if(ans < target){
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(10) << (l+r)/2 << ln;

    return 0;
}