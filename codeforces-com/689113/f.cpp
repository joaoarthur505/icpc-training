#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

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
const ll MOD = 998'244'353;

vvll mult(vvll& m1, vvll& m2){
    vvll resp(2, vll(2,0));
    forn(i,0,2) forn(k,0,2) forn(j,0,2){
        resp[i][j] += m1[i][k]*m2[k][j];
    }
    forn(i,0,2) forn(j,0,2) resp[i][j] %= MOD;
    return resp;
}

ll expll(ll b, ll e){
    ll resp = 1;
    ll aux = b;
    while(e){
        if(e&1) resp = (resp*aux)%MOD;
        e >>= 1;
        aux = (aux*aux)%MOD;
    }
    return resp;
}

ll inv(ll b){
    return expll(b, MOD-2);
}

vvll expvv(vvll& b, ll e){
    vvll resp = {{1,0},{0,1}};
    vvll aux = b;
    while(e){
        if(e&1) resp = mult(resp,aux);
        e >>= 1;
        aux = mult(aux, aux);
    }
    return resp;
}

pll inverte(vvll& mat, pll v){
    ll a = mat[0][0];
    ll b = mat[0][1];
    ll c = mat[1][0];
    ll d = mat[1][1];
    ll det = ((a*d-b*c)%MOD + MOD)%MOD;
    assert(det != 0);

    pll resp = {0,0};
    resp.first =  ((v.first*( d) + v.second*(-b))%MOD + MOD)%MOD;
    resp.second = ((v.first*(-c) + v.second*( a))%MOD + MOD)%MOD;
    ll invdet=  inv(det);
    resp.first = (resp.first*invdet)%MOD;
    resp.second = (resp.second*invdet)%MOD;
    return resp; 
}

void edge(ll a, ll b, ll n, ll m, ll vn, ll vm){
    // cout << "AAAAAAAAAAAA" << ln;
    ll l = (a*inv(2))%MOD;
    debug(l);
    pll v;
    v.first  = (vn*inv(expll(l, n)))%MOD;
    v.second = (vm*inv(expll(l, m)))%MOD;
    debug(v.first);
    debug(v.second);
    vvll toinv = {{n,1}, {m,1}};
    auto [alp, bet] = inverte(toinv, v);
    debug(alp);
    debug(bet);
    cout << bet << " " << (l*(alp+bet))%MOD << ln;
    return;
}
 
void solve(){
    ll a, b,n,m, vn, vm;
    cin >> a >> b >>n >> m >> vn >> vm;
    
    if((a*a+4*b)%MOD == 0){
        edge(a,b,n, m, vn,vm);
        return;
    }

    vvll mat = {{a,b}, {1,0}};
    vvll mn = expvv(mat,n);
    vvll mm = expvv(mat,m);

    vvll toinv = {mn[1], mm[1]};
    debugv(toinv[0]);
    debugv(toinv[1]);
    pll v = {vn, vm};
    debug(v.first);
    debug(v.second);
    pll resp = inverte(toinv, v);
    cout << resp.second << " " << resp.first << ln;
}
int main() {
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0; 
}
