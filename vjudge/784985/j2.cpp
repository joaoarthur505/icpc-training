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
#define debug(xx) trace(cout << __LINE__ << ": " #xx " = " << xx << ln)

const ld DINF = 1e9;
const ll MAXIT = 100;
const ld eps = 1e-12;

v64 a,b;
ll n, p, q; 

int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ld f(ld x){
    ld y = 1;
    ll best_a = 0;
    ll best_b = 1;
    forn(i, 0, n){
        ld curr_y = (1 - a[i]*x)/b[i];
        if(cmp(curr_y, y) < 0) y = curr_y;
    }

    return p*x+q*y;
}

int main(){
    _;
    cin >> n >> p >> q;
    a.resize(n);
    b.resize(n);

    ll maxa = 0;

    forn(i,0,n) {
        cin >> a[i];
        cin >> b[i];

        maxa = max(maxa, a[i]);
    }

    ld l = 0, r = 1./maxa;
    forn(i, 0, MAXIT){
        ld m1 = (2*l + r)/3, m2 = (l + 2*r)/3;
        ld f1 = f(m1), f2 = f(m2);

        if(cmp(f1,f2) <= 0) l = m1;
        else r = m2;
    }

    ld ans = (l+r)/2;
    cout << fixed << setprecision(15) << f(ans) << ln;
    return 0;
}