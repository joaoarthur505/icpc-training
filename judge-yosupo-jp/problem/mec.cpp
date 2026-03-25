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

const ld DINF = 1e18;
const ld eps = 1e-10;
const ld pi = 2*acos(0);

#define sq(x) ((x)*(x))

int cmp(ld x, ld y = 0, ld tol = eps) {
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
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
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
};

ld norm_sq(pt p){ return p*p;}

ld dist_sq(pt p, pt q){ return norm_sq(p - q);}

ld dist(pt p,pt q){ return sqrt(dist_sq(p, q));}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

pt perp(pt p){ return {-p.y, p.x}; }

ld ccRadius(pt a, pt b, pt c) {
    ld s = sarea(a,b,c);
    if(s == 0) return DINF;
	return dist(a,b)*dist(b,c)*dist(c,a)/(4*abs(s));
}

pt ccCenter(pt a, pt b, pt c) {
	c = c-a, b = b-a;
    if((b^c) == 0) return {DINF,DINF};
	return a + perp((b*norm_sq(c)-c*norm_sq(b)))/(2*(b^c));
}

// testar se r(1+eps) é melhor q r+eps;
pair<pt, ld> mec(vector<pt> v) {
	shuffle(v.begin(), v.end(), mt19937(time(0)));
	pt o = v[0];
	ld r = 0;
	forn(i, 0, sz(v)) if (dist(o, v[i]) > r*(1+eps)) {
		o = v[i], r = 0;
		forn(j, 0, i) if (dist(o, v[j]) > r*(1+eps)) {
			o = (v[i] + v[j]) / 2;
            r = dist(o, v[i]);
			forn(k, 0, j) if (dist(o, v[k]) > r*(1+eps)) {
				o = ccCenter(v[i], v[j], v[k]);
                r = dist(o, v[i]);
			}
		}
	}
	return {o, r};
}

int main() {
    _; ll n; cin >> n;
    vector<pt> v(n);
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        v[i] = pt(a,b);
    }

    auto [p, r] = mec(v);

	trace(
		cout << p.x << " " << p.y << ln;
		cout << fixed << setprecision(15) << r <<ln;
		cout << fixed << setprecision(15) << r*(1+eps) <<ln;
		cout << fixed << setprecision(15) << r*(1-eps) <<ln;
	);

    string ans(n, '0');
    forn(i, 0, n){
		trace(cout << fixed << setprecision(15) << dist(p, v[i]) <<ln;);
		ld d = dist(p, v[i]);

        if(d < r*(1+eps) && d > r*(1-eps)) ans[i] = '1';
    }

    cout << ans << ln;

    return 0;
}
