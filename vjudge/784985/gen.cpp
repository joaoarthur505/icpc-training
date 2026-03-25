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


mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}


#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vb = vector<bool>;

using ld = long double;
struct Line {
    ld a, b, c;
};

bool half(Line m) { return m.a < 0 || (m.a == 0 && m.b < 0); }

bool operator<(Line m, Line n) {
    return make_pair(half(m), m.b * n.a) < make_pair(half(n), m.a * n.b);
}

const ld INF = 1e18;

const ll MAXN = 10;
const ll MAXSIZE = 1000'000;


tuple<ld, ld, ld> LineIntersection(Line m, Line n) {
    ld d = m.a * n.b - m.b * n.a;
    ld x = m.c * n.b - m.b * n.c;
    ld y = m.a * n.c - m.c * n.a;
    return {x, y, d};
}

struct HalfplaneSet : multiset<Line> {
    HalfplaneSet() {
        insert({+1, 0, INF}), insert({0, +1, INF});
        insert({-1, 0, 0}), insert({0, -1, 0});
    }

    auto adv(auto it, int z) {
        return (z == -1 ? --(it == begin() ? end() : it)
                        : ++it == end() ? begin() : it);
    }

    bool chk(auto it) {
        Line l = *it, pl = *adv(it, -1), nl = *adv(it, +1);
        auto [x, y, d] = LineIntersection(pl, nl);
        ld sat = l.a * x + l.b * y - l.c * d;
        if (d < 0 && sat < 0) return clear(), 0;
        if ((d > 0 && sat <= 0) || (d == 0 && sat < 0)) return erase(it), 1;
        return 0;
    }

    void Cut(Line l) {
        if (empty()) return;
        auto it = insert(l);
        if (chk(it)) return;
        for (int z : {-1, +1})
            while (size() && chk(adv(it, z)));
    }

    ld Maximize(ld a, ld b) {
        if (empty()) return -1 / 0.;
        auto it = lower_bound({a, b});
        if (it == end()) it = begin();
        auto [x, y, d] = LineIntersection(*adv(it, -1), *it);
        return (1.0 * a * x + 1.0 * b * y) / d;
    }
};

ld solve(ll n, ll p, ll q, v64& a, v64& b) {

    HalfplaneSet hp;
    rep(i, 0, n) {
        hp.Cut({(ld)a[i], (ld)b[i], 1});
    }

    return hp.Maximize(p, q);
}

int main(){
    _; 
    
    ll n = uniform(1, MAXN);
    ll p = uniform(1, MAXSIZE);
    ll q = uniform(1, MAXSIZE);
    cout << n << " " << p << " " << q << ln;

    v64 a(n);
    v64 b(n);
    forn(i,0,n) a[i] = uniform(1,MAXSIZE);
    forn(i,0,n) b[i] = uniform(1,MAXSIZE);

    forn(i, 0, n){
        cout << a[i] << " " << b[i] << ln;
    }

    ld resp = solve(n,p,q,a,b);
    cout << fixed << setprecision(15) << resp << ln;
    return 0;
}