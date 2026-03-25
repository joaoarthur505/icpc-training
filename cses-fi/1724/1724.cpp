#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

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
const ll MOD = 1000000007;

ll new_min(ll a,ll b){
    if(a == -1) return b;
    if(b == -1) return a;
    return min(a, b);
}

ll new_sum(ll a, ll b){
    if(a == -1 || b == -1) return -1;
    return a+b;
}

#define MODULAR false
template<typename T> struct matrix : vector<vector<T>> {
    ll n, m;
    void print() {
        forn(i,0,n) {
            forn(j,0,m) cout << (*this)[i][j] << " ";
            cout << endl;
        }
    }

    matrix(ll n_, ll m_, bool ident = false) :
            vector<vector<T>>(n_, vector<T>(m_, -1)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
            forn(i,0,n) (*this)[i][i] = 0;
        }
    }
    matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
        n(sz(c)), m(sz(c[0])) {}
    matrix(const initializer_list<initializer_list<T>>& c) {
        vector<vector<T>> val;
        for (auto& i : c) val.push_back(i);
        *this = matrix(val);
    }

    matrix<T> operator*(matrix<T>& r) {
        assert(m == r.n);
        matrix<T> M(n, r.m);
        forn(i,0,n) forn(k,0,m) forn(j, 0, r.m){
            T add = new_sum((*this)[i][k], r[k][j]);
#if MODULAR
#warning Usar matrix<ll> e soh colocar valores em [0, MOD) na matriz!
            M[i][j] += add%MOD;
            if (M[i][j] >= MOD) M[i][j] -= MOD;
#else
            M[i][j] = new_min(M[i][j], add);
#endif
        }
        return M;
    }
    matrix<T> operator^(ll e){
        matrix<T> M(n, n, true), at = *this;
        while (e) {
            if (e&1) M = M*at;
            e >>= 1;
            at = at*at;
        }
        return M;
    }
};

int main() {
    _; ll n, m, k; cin >> n >> m >> k;
    matrix<ll> g(n, n);
    forn(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--;
        b--;

        g[a][b] = new_min(g[a][b], c);
    }
    g = g^k;

    cout << g[0][n-1] << ln;

    return 0;
}
