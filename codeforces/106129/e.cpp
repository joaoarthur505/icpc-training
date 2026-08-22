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

ld get_t(pt v, line r){
    return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s){
    if(cmp((r.p-r.q) ^(s.p - s.q), 0) == 0) return pt(DINF, DINF);
    r.q = r.q-r.p, s.p = s.p - r.p, s.q = s.q - r.p;
    return r.q * get_t(r.q,s) + r.p;
}

pair<pt, pt> cline(pt o, ld r, pt a, pt b){
    pt h = foot(o, a, b);
    pt in(DINF, DINF);
    ld d = norm(h-o);
    if(cmp(d,r) == 0) return {h, in};
    if(cmp(d,r) == 1) return {in, in};
    return perp_pts(line(o,h), sqrt(r*r - d*d));
}

bool testa(pt a, pt b, pt c, pt d, pt x){
    if(!ccw(d,c,x)) return false;
    if(!ccw(c,x,b)) return false;
    if(!ccw(x,b,a)) return false;

    if(!(cmp((d-c)*(x-d)) < 0)) return false;
    if(!(cmp((c-x)*(b-x)) < 0)) return false;
    if(!(cmp((x-b)*(a-b)) < 0)) return false;

    return true;
}

vector<pt> best_pt(pt a, pt b, pt c, pt d){
    pt o = (b+c)/2;
    pt m = o + rot(rot(rot(c-o)));
    
    vector<pt> cand = {m};

    debug(b);
    debug(c);
    debug(o); 
    debug(m);

    auto circ_reta = [&](pt ol, ld r, pt p1, pt p2){
        auto par = cline(ol, r, p1, p2);
        pt p = par.first;
        if(p == p1) p = par.second;
        cand.push_back(p);
    };

    circ_reta(o, dist(c,o), b, b+rot(a-b));
    circ_reta(o, dist(c,o), c, c+rot(d-c));
    circ_reta(o, dist(c,o), c, d);
    circ_reta(o, dist(c,o), b, a);

    cand.push_back(inter(line(a,b), line(c,d)));
    
    vector<pt> bomcand;
    for(auto p : cand) if(testa(a,b,c,d,p)) bomcand.push_back(p);

    return bomcand;
}

int main(){
    _; ll n; cin >> n;
    vector<pt> poly(n);

    forn(i, 0, n) cin >> poly[i];

    ld best_incr = 0;

    forn(i, 0, n){
        auto cand = best_pt(poly[(i+2)%n], poly[(i+1)%n], poly[(i-1 + n)%n], poly[(i-2 + n)%n]);
        
        debug(poly[i]);
        trace(cout << (i+2)%n << " " << (i+1)%n << " " << (i-1 + n)%n << " " << (i-2 + n)%n << ln;)
        
        debug(sz(cand));
        for(pt p : cand){   
            trace(cout << fixed << setprecision(4) << p.x << " " << p.y << ln;)
            ld incremento = dist(poly[(i-1+n)%n], p) + dist(poly[(i+1)%n], p);
            incremento -= dist(poly[(i-1 + n)%n], poly[i]) + dist(poly[(i+1)%n], poly[i]);
            
            if(cmp(incremento, best_incr) > 0) best_incr = incremento;
            trace( cout << fixed << setprecision(15) << incremento << ln; )
        }

        trace(cout << "-------------------\n\n");
    }
 
    cout << fixed << setprecision(15) << best_incr << ln;

    return 0;
}