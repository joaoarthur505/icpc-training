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
const ll eps = 1e-9;

ll cmp(ld x, ld y = 0, ld tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct cluster{
    ll l, r, sum;
    
    ld x(){ 
        return (ld)sum/(r-l+1);
    }

    cluster& operator +=(const cluster& c) {
        r = max(r, c.r);
        l = min(l, c.l);
        sum += c.sum;
        return *this;
    }

    bool operator < (const cluster c) const {
		return sum*(c.r - c.l + 1) < c.sum*(r-l+1);
	}
};

ld solve(vector<ll>& x){
    ll n = sz(x);

    vector<cluster> pilha;

    forn(i, 0, n){
        cluster curr;
        curr.l = curr.r = i;
        curr.sum = x[i];

        trace(
            if(!pilha.empty()){
                cluster last = pilha.back();
                debug(curr.sum*(last.r - last.l + 1));
                debug(last.sum*(curr.r - curr.l + 1));
            }
        );

        while(!pilha.empty() && curr < pilha.back()){
            curr += pilha.back();
            pilha.pop_back();
        }

        pilha.push_back(curr);
    }

    debug(sz(pilha));

    ld resp = 0;

    for(auto c : pilha){
        forn(i, c.l, c.r+1){
            resp += (c.x() - x[i])*(c.x() - x[i]);
        }
    }

    return resp;
}

int main() {
    _; ll n; cin >> n;
    vector<ll> x(n), y(n);
    forn(i, 0, n){
        cin >> x[i] >> y[i];
    }

    cout << fixed << setprecision(10) << solve(x) + solve(y) << ln;
    return 0;
}
