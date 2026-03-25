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

#define debugv(v) trace({cout << #v": "; for (auto u : v) cout<< u << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld eps = 0.001;
const ll POW = 1000000;

struct pt {
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x and y == p.y;
    }
    bool operator != (const pt p) const {
        return x != p.x or y != p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ll c) const { return pt(x*c, y*c); }
    ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
    friend ostream& operator << (ostream& out, pt& p) {
        return out << p.x << "," << p.y;
    }
};

ll sarea2(pt p, pt q, pt r) {
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
    return sarea2(p, q, r) > 0;
}

bool colin(pt p, pt q, pt r){
    return sarea2(p, q, r) == 0;
}

bool colin_same_side(pt p, pt q, pt r){
    return colin(p, q, r) && (q-p)*(r-p) > 0;
}

ll quad(pt p){
    return (p.x<0)^3*(p.y<0);
}

bool compare_angle(pt p, pt q){ // return p < q;
    if(quad(p) != quad(q)) return quad(p) < quad(q);
    return ccw(q, pt(0,0), p);
}

ll n, m;
vector<pt> choc;
vector<pt> strawb;

ll count_left(pt p, pt q){
    bool strawb_up = false, strawb_down = false;
    forn(i, 0, m){
        if(ccw(p, q, strawb[i])) return 0;
        if(colin(p, q, strawb[i])){ 
            if((p-strawb[i])*(q-strawb[i]) < 0) return 0;
            if((q-p)*(strawb[i]-p) > 0) strawb_up = true;
            if((q-p)*(strawb[i]-p) < 0) strawb_down = true;
        }
    }

    if(strawb_up && strawb_down) return 0;

    ll cnt = 0;
    forn(i, 0, n){
        if(ccw(p, q, choc[i])) cnt++;
    }

    return cnt+2;
}

int main(){
    _; cin >> n >> m;
    choc.resize(n);
    strawb.resize(m);

    forn(i, 0, n){
        ld a, b; cin >> a >> b;
        a = POW*a+eps;
        b = POW*b+eps;
        choc[i] = pt(a, b);
    }
    forn(i, 0, m){
        ld a, b; cin >> a >> b;
        a = POW*a+eps;
        b = POW*b+eps;
        strawb[i] = pt(a, b);
    }

    ll best_cut = 0; 
    forn(i, 0, n){
        forn(j, 0, m){
            if(i == j) continue;
            best_cut = max(best_cut, count_left(choc[i], choc[j]));
        }
    }

    cout << best_cut<< ln;

    return 0;
}