
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define debug(u) trace(cout << #u " = " << u << ln);
#define debugv(v) trace(cout << #v ": "; for(auto xx : v) cout << xx << " "; cout << ln)
#define debugm(v) trace(cout << #v ": "; for(auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln;)

const ll INF = 1'000'000'000'000'000ll;

void ler(ll& zz){
    string s; cin >> s;
    ll n = sz(s);

    string s1 = s.substr(0,n-3);
    string s2 = s.substr(n-2,2);
    ll x = stoi(s1);
    ll y = stoi(s2);
    zz = x*100 + y;
}

struct pt{
    ll x, y, volta;
    pt(ll x_,ll y_, ll v = 0) : x(x_), y(y_), volta(v) {};

    pt operator - (const pt p) const { return pt(x - p.x, y - p.y);}
    ll operator ^ (const pt p) const { return x*p.y - y*p.x;}

    ll sarea2(pt p, pt q, pt r) const{
        return (q-p)^(r-p);
    }

    bool ccw(pt p, pt q, pt r) const{
        return sarea2(p, q, r) > 0;
    }

    ll quad(pt p) const{
        return (p.x < 0) ^ 3*(p.y < 0);
    }

    bool compare_angle(pt p, pt q) const{
        if(quad(p) != quad(q)) return quad(p) < quad(q);
        return ccw(q, pt(0,0), p);
    }

    bool operator < (const pt q) const{
        pt p = *this;
        if(p.volta != q.volta) return p.volta < q.volta;
        return compare_angle(p, q);
    }

    friend ostream& operator << (ostream& out, const pt& p) {
        return out << "(" << p.x << ", " << p.y << ", v:" << p.volta << ")";
    }
};

pt rot(pt p){
    ll volta = p.volta;
    if(p.y > 0) return {-p.x, -p.y, volta};
    if(p.y < 0) return {-p.x, -p.y, volta+1};
    if(p.x < 0) return {-p.x, -p.y, volta+1};
    return {-p.x, -p.y, volta};
}

int main(){
    _;
    ll n;
    ll h;  
    cin >> n;
    ler(h);

    vector<tuple<ll, ll, ll>> vec(n);
    forn(i,0,n){
        ll a, b, c;
        ler(a);
        ler(b);
        ler(c);
        vec[i] = {c,a,b};
    }
    
    ll cx, cy;
    ler(cx); ler(cy);

    sort(vec.rbegin(), vec.rend());

    set<pt> s;

    auto pega = [&](pt t){
        auto it = s.lower_bound(t);

        if(it == s.begin()) return pt(INF,INF, INF);
        return *prev(it);
    };

    forn(i,0,n){
        debug(i);
        auto [hh, x, y] = vec[i];
        x -= cx;
        y -= cy;

        if(x == 0 && y == 0) continue;
        
        pt p(x,y, 0);
        
        auto a = pega(rot(p));

        auto b = pega(rot(a));

        trace(cout << "p: " << p.x << " " << p.y << " " << p.volta << ln);
        trace(cout << "a: " << a.x << " " << a.y << " " << a.volta << ln);
        trace(cout << "b: " << b.x << " " << b.y << " " << b.volta << ln);

        if(b.x != INF && rot(p) < b){
            ll resp = h - hh;
            debug(resp);
            resp = max(resp, 0ll);
            cout << resp/100 << "." << resp%100 << ln;
            return 0;
        }

        s.insert(p);
        s.insert(rot(rot(p)));
        s.insert(rot(rot(rot(rot(p)))));
        debugv(s); 
    }

    cout << -1 << ln;
}


