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

const ld TOL = 1e-6;
const ll MAXIT = 100;
const ll MAXN = 10;
const ll MAXSIZE = 1000;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

v64 a,b;
ll n, m, o;

int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

void gen(){
    _;
    n = uniform(1, MAXN);
    m = uniform(1, MAXSIZE);
    o = uniform(1, MAXSIZE);

    a.resize(n);
    b.resize(n);
    
    forn(i, 0, n){
        a[i] = uniform(1, MAXSIZE);
        b[i] = uniform(1, MAXSIZE);
    }
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

line convert(ll a_, ll b_){
    pt q = {0.0, 1.0/b_}; // invertido
    pt p = {1.0/a_, 0.0};
    trace(
        cout << "[" << q.x << " " << q.y << "]" << ln;
        cout << "[" << p.x << " " << p.y << "]" << ln;
        cout << ln;
    );
    return line(p,q);
}

pt hpi_1d(vector<line> v, pt best_dir, ll n_, line suport, ll minx, ll maxx){
	pt low = inter(line(pt(minx, 0), pt(minx,1)), suport), upp = inter(line(pt(maxx, 0), pt(maxx,1)), suport);
	forn(i, 0, n_){
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

	ll n_ = sz(v);
	pt best(1, 1);

	forn(i, 0, n_){
		debug(best);
		debug(v[i]);
		if(ccw(v[i].p, v[i].q, best)) continue;
		best = hpi_1d(v, best_dir, i, v[i], minx, maxx);
		assert(!(best ==pt(DINF, DINF)));
	}

	return best;
}

ld solve(){
    vector<line> linhas;
	linhas.push_back(line(pt(1,1), pt(0,1)));
	linhas.push_back(line(pt(0,0), pt(1,0)));
    forn(i,0,n) linhas.push_back(convert(a[i], b[i]));

	forn(i, 0, sz(linhas)) debug(linhas[i]);

    auto resp = hpi(linhas, pt(m,o), 0, 1); 
    return resp*pt(m,o);
}

ld f(ld x){
    ld y = 1;
    forn(i, 0, n){
        ld curr_y = (1 - a[i]*x)/b[i];
        if(cmp(curr_y, y) < 0) y = curr_y;
    }
    debug(x);
    debug(y);

    return m*x+o*y;
}

ld solve2(){
    ll maxa = 1;
    forn(i,0,n) maxa = max(maxa, a[i]);

    ld l = 0, r = 1./maxa;
    forn(i, 0, MAXIT){
        ld m1 = (2*l + r)/3, m2 = (l + 2*r)/3;
        ld f1 = f(m1), f2 = f(m2);

        if(cmp(f1,f2) <= 0) l = m1;
        if(cmp(f1,f2) >= 0) r = m2;
    }

    ld ans = (l+r)/2;

    return f(ans);
}

int main(){
    _;
    ll cnt = 0;
    while(true){
        cout << cnt++ << ln;
        gen();
        ld ans1 = solve();
        ld ans2 = solve2();

        if(cmp(abs(ans1 - ans2),TOL*max(max(ans1, ans2),(ld)1)) >= 0){
            cout << n << " " << m << " " << o << ln;
            forn(i, 0, n){
                cout << a[i] << " " << b[i] << ln;
            }

            cout << "ans1: " << fixed << setprecision(15) << ans1 << ln;
            cout << "ans2: " << fixed << setprecision(15) << ans2 << ln;
            break;
        }
    }

    return 0;
}