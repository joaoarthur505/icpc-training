#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
const ll INF = 99;
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << setw(2) << xx << " "; cout << ln)


vector<vll> create(vector<string>& mat, ll n, ll m, char c){
    vector<vll> nxt(n, vll(m, INF));
    forn(i,0,n){
        for(ll j = m-1; j >= 0; j--){
            if(mat[i][j] == c) nxt[i][j] = j;
            else if(j < m-1) nxt[i][j] = nxt[i][j+1];
        }
    }
    debug(c);
    forn(i,0,n){debugv(nxt[i]);}
    return nxt;
}

int main() {
    _;

    ll n, m; cin >> n >> m;
    vector<string> mat(n);
    vector<string> mat2(m, string(n,'#'));
    forn(i,0,n) cin >> mat[i];
    if(n > m){
        forn(i,0,n) forn(j,0,m) mat2[j][i] = mat[i][j];
        swap(n,m);
        swap(mat2, mat);
    }

    vector<vector<vll>> nxt(5);
    nxt[0] = create(mat, n, m, 'W');
    nxt[1] = create(mat, n, m, 'A');
    nxt[2] = create(mat, n, m, 'L');
    nxt[3] = create(mat, n, m, 'D');
    nxt[4] = create(mat, n, m, 'O');

    ll resp = INF;
    forn(i,0,n){
        forn(j,0,m){
            vll minc = {INF,INF,INF,INF,INF};
            forn(h,0,n-i){
                forn(t,0,5) minc[t] = min(minc[t], nxt[t][i+h][j]);
                if(i == 2 && j == 2){debug(h); debugv(minc);}
                ll l = *max_element(minc.begin(), minc.end());
                if(l < INF) resp = min(resp, (l-j+1)*(h+1));
            }
        }
    }
    if(resp < INF) cout << resp << ln;
    else cout << "impossible" << ln;
    return 0;
}
