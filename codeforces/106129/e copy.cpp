#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
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
#define debugv(v) trace(cout << #v ": "; for(auto xx : v) cout << xx << " "; cout << ln)
#define debugm(v) trace(cout << #v ": "; for(auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll DINF = 1e18;
const ld eps = 1e-15;

ll cmp(ld x, ld y = 0, ld tol = eps){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct pt {
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    
    bool operator == (const pt p) const {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }

    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ld c) const { return pt(x*c, y*c);}
    pt operator / (const ld c) const { return pt(x/c, y/c);}
    ld operator * (const pt p) const { return x*p.x + y*p.y;}
    ld operator ^ (const pt p) const { return x*p.y - y*p.x;}
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
    friend ostream& operator << (ostream& out, pt& p) {
        return out << p.x << " " << p.y;
    }
};

struct line {
    pt p, q;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
};

ld norm_sq(pt p){ return p*p;}

ld norm(pt p){ return sqrt(norm_sq(p));}

ld dist_sq(pt p, pt q){ return norm_sq(p-q);}

ld dist(pt p, pt q){ return sqrt(dist_sq(p,q));}

pt rot(pt p) {return pt(p.y, -p.x);}

ld sarea(pt p, pt q, pt r){
    return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r, bool strict = true){
    return cmp(sarea(p,q,r), 0) > 0 || (!strict && cmp(sarea(p,q,r) == 0));
}

bool cima(pt b, pt c, pt x){
    return !ccw(c,b,x);
}

pair<pt, pt> perp_pts(line l, ld d){
    pt dir = l.p - l.q;
    pt r = pt(dir.y, -dir.x);
    pt k = r*(d/norm(r));
    return {l.q+k, l.q - k};
}

pt foot(pt p, pt a, pt b){
    pt dir = b-a;
    return (dir*((p-a)*dir))/(dir*dir) + a;
}

pair<pt, pt> cline(pt o, ld r, pt a, pt b){
    pt h = foot(o, a, b);
    pt in(DINF, DINF);
    ld d = norm(h-o);
    if(cmp(d,r) == 0) return {h, in};
    if(cmp(d,r) == 1) return {in, in};
    return perp_pts(line(o,h), sqrt(r*r - d*d));
}

pt best_pt(pt a, pt b, pt c, pt d){
    pt o = (b+c)/2;
    pt m = o + rot(rot(rot(c-o)));
  
    debug(b);
    debug(c);
    debug(o); 
    debug(m);

    if((m-b)*(a-b) > 0){
        auto par = cline(o, dist(c, o), b, b+rot(a-b));

        pt p = par.first;
        if(p == b) p = par.second;

        return p;
    }
    if((m-c)*(d-c) > 0){
        auto par = cline(o, dist(c, o), c, c+rot(d-c));

        pt p = par.first;
        if(p == c) p = par.second;

        return p;
    }
    return m;
}

int main(){
    _; ll n; cin >> n;
    vector<pt> poly(n);

    forn(i, 0, n) cin >> poly[i];

    ld best_incr = 0;

    forn(i, 0, n){
        pt p = best_pt(poly[(i+2)%n], poly[(i+1)%n], poly[(i-1 + n)%n], poly[(i-2 + n)%n]);
        debug(poly[i]);
        trace(cout << (i+2)%n << " " << (i+1)%n << " " << (i-1 + n)%n << " " << (i-2 + n)%n << ln;)
        trace(cout << fixed << setprecision(4) << p.x << " " << p.y << ln;)
        ld incremento = dist(poly[(i-1+n)%n], p) + dist(poly[(i+1)%n], p);
        incremento -= dist(poly[(i-1 + n)%n], poly[i]) + dist(poly[(i+1)%n], poly[i]);

        trace( cout << fixed << setprecision(15) << incremento << ln; )

        if(cmp(incremento, best_incr) > 0) best_incr = incremento;
        trace(cout << "-------------------\n\n");
    }
 
    cout << fixed << setprecision(15) << best_incr << ln;

    return 0;
}