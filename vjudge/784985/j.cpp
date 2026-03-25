// Perfomance geral (seguro p/ CP)
//  #pragma GCC optimize("O3,unroll-loops,fast-math")

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
const ld pi = 2*acos(0.0);
const ld DINF = 1e18;
const ld eps = 1e-20;

#define sq(x) ((x)*(x))

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

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
		return cmp(x, p.x) == 0 and cmp(y, p.y) == 0;
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
		return out << "(" << p.x << ", " << p.y << ") ";
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
	friend ostream& operator << (ostream& out, line& l) {
		return out << "(" << l.p << ", " << l.q << ") ";
	}
};

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return cmp(sarea(p, q, r),0) >= 0;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s) { // r inter s
	if (cmp((r.p - r.q) ^ (s.p - s.q), 0) == 0) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

line convert(ll a, ll b){
    pt q = {0.0, 1.0/b}; // invertido
    pt p = {1.0/a, 0.0};
    trace(
        cout << "[" << q.x << " " << q.y << "]" << ln;
        cout << "[" << p.x << " " << p.y << "]" << ln;
        cout << ln;
    );
    return line(p,q);
}

pt hpi_1d(vector<line> v, pt best_dir, ll n, line suport, ll minx, ll maxx){
	pt low = inter(line(pt(minx, 0), pt(minx,1)), suport), upp = inter(line(pt(maxx, 0), pt(maxx,1)), suport);
	forn(i, 0, n){
		pt intersection = inter(v[i], suport);
		debug(low);
		debug(upp);
		debug(intersection);
		debug(v[i]);

		if(!ccw(v[i].p, v[i].q, low)) low = intersection;
		else if(!ccw(v[i].p, v[i].q, upp)) upp = intersection;
	}

	if(cmp(low.x, upp.x) > 0) return {DINF, DINF};
	
	if(cmp(best_dir*low, best_dir*upp) <= 0) return upp;
	return low;
}

pt hpi(vector<line> v, pt best_dir, ll minx, ll maxx){
	shuffle(v.begin(), v.end(), rng);

	ll n = sz(v);
	pt best(1, 1);

	forn(i, 0, n){
		debug(best);
		debug(v[i]);
		if(ccw(v[i].p, v[i].q, best)) continue;
		best = hpi_1d(v, best_dir, i, v[i], minx, maxx);
		assert(!(best ==pt(DINF, DINF)));
	}

	return best;
}

int main(){
    _;
    ll n, p, q; 
    cin >> n >> p >> q;
    v64 a(n);
    v64 b(n);

    forn(i,0,n) {
        cin >> a[i];
        cin >> b[i];
    }

    vector<line> linhas;
	linhas.push_back(line(pt(1,1), pt(0,1)));
	linhas.push_back(line(pt(0,0), pt(1,0)));
    forn(i,0,n) linhas.push_back(convert(a[i], b[i]));

	forn(i, 0, sz(linhas)) debug(linhas[i]);

    auto resp = hpi(linhas, pt(p,q), 0, 1);  

    ld ans = resp*pt(p,q);
	cout << fixed << setprecision(15) << ans << ln;
	return 0;

	ld teorical_ans; 
    cin >> teorical_ans;
    
	if(abs(ans - teorical_ans) < 0.000001){
        cout << 1 << ln;
    }else{
        cout << 0 << ln;
    }

    debug(ans);

    trace( 
        cout << fixed << setprecision(15) << ans << ln;
        cout << fixed << setprecision(15) << teorical_ans << ln;
        cout << fixed << setprecision(15) << abs(ans - teorical_ans) << ln;
    );
    return 0;
}