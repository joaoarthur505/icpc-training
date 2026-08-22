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

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for(auto xx : v) cout << xx << " "; cout << ln)
#define debugm(v) trace(cout << #v ": "; for(auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _;   
    ll n, m; cin >> n >> m;
    vector<string> matg(n);
    forn(i,0,n) cin >> matg[i];

    ll lll = 0;
    forn(i,0,n) {
        forn(j,0,m) if(matg[i][j] == '#'){
            ll p1 = j;
            while(p1 < m && matg[i][p1] == '#') p1++;
            lll = p1-j;
            break;
        }
        if(lll != 0) break;
    }
    vll pos;
    for(ll d = 1; d*d <= lll; d++){
        if(lll%d) continue;
        pos.push_back(d);
        if(d*d != lll) pos.push_back(lll/d);
    }

    ll resp = 0; 
    debugv(pos);
    for(ll d : pos){
        debug(d);
        auto mat = matg;
        bool dbom = true;

        
        forn(i,0,n) {
            forn(j,0,m) if(mat[i][j] == '#'){
                trace(cout << i << " " << j << ln;)
                trace(forn(x,0,n) cout << mat[x] << ln;);
                if(i+d-1 >= n || j+d-1 >= m){
                    debug(1);
                    dbom = false;
                    break;
                }
                
                forn(x,0,d){
                    forn(y,0,d){
                        if(mat[i+x][j+y] == '.'){
                            debug(2);
                            dbom = false;
                            break;
                        }
                        mat[i+x][j+y] = '.';
                    }
                    if(!dbom) break;
                }
                
                trace(forn(x,0,n) cout << mat[x] << ln;);
                debug(dbom);
                if(!dbom) break;
            }
            if(!dbom) break;
        }

        if(dbom) resp = max(resp, d);
        trace(cout << "--------------------------\n\n\n";)
    }

    cout << resp << ln;
    return 0;
}