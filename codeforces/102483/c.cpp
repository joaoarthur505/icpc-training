#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

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
const ld eps = 1e-9;
const ld pi = 2*acos(0);

#define sq(x) ((x)*(x))

ll cmp(ld x, ld y = 0, ld tol = eps) {
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

pt dir(ld ang){
    return pt(cos(ang), sin(ang));
}

int main() {
    _; ll n; cin >> n;
    vector< vll> g(n);

    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pt> point(n);
    vector<pair<ld, ld>> ang(n);

    ang[0] = {0, 2*pi};
    point[0] = pt(0,0);

    function<void (ll, ll)> dfs = [&](ll curr, ll pai){
        if(sz(g[curr]) == 1 && pai != -1) return; 
        ld step = (ang[curr].second - ang[curr].first);
        if(pai != -1) step = step/(sz(g[curr])-1);
        ld curr_ang = ang[curr].first;

        for(auto nxt : g[curr]) if(nxt != pai){
            ang[nxt] = {curr_ang, curr_ang + step};
            curr_ang += step;
            point[nxt] = point[curr] + dir((ang[nxt].first + ang[nxt].second)/2);
        }
    };

    dfs(0, -1);

    

    return 0;
}
