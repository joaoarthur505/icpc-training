#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ll SID = 8;
const ll SIZ = SID*SID;

#define MODULAR false
template<typename T> struct matrix : vector<vector<T>> {
    ll n, m;
    void print() {
        forn(i,0,n) {
            forn(j,0,m) cout << fixed << setprecision(2) << (*this)[i][j] << " ";
            cout << endl;
        }
    }

    matrix(ll n_, ll m_, bool ident = false) :
            vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
            forn(i,0,n) (*this)[i][i] = 1;
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
            T add = (*this)[i][k] * r[k][j];
#if MODULAR
#warning Usar matrix<ll> e soh colocar valores em [0, MOD) na matriz!
            M[i][j] += add%MOD;
            if (M[i][j] >= MOD) M[i][j] -= MOD;
#else
            M[i][j] += add;
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
    void apply_transform(matrix M, ll e){
        auto& v = *this;
        while (e) {
            if (e&1) v = M*v;
            e >>= 1;
            M = M*M;
        }
    }
};

int main() {
    _; ll k; cin >> k;

    matrix<ld> trans(SIZ, SIZ);
    forn(i, 0, SID)
    forn(j, 0, SID){
        ll ind = SID*i+j;
        v64 reach;
        if(i > 0) reach.push_back(ind-SID);
        if(i < SID-1) reach.push_back(ind+SID);
        if(j > 0) reach.push_back(ind-1);
        if(j < SID-1) reach.push_back(ind+1);
        ld prob = (ld)1/sz(reach);
        for(auto to : reach) trans[ind][to] = prob;
    }

    trace(trans.print());

    trans = trans^(k);
    ld e = 0;
    forn(i, 0, SIZ){
        ld factor = 1;
        forn(j, 0, SIZ) factor *= (1 - trans[j][i]);
        e += factor;
    }

    ld resp = roundeven(e*1e6)/1e6;
    cout << fixed << setprecision(6) << resp << ln;
    return 0;
}
