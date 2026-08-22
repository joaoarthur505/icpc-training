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
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n, m; cin >> n >> m;

    vector<tuple<ll,ll,ll>> edges(m);
    vector<tuple<ll,ll,ll>> sl;
    forn(j,0,m){
        ll i, d, c; cin >> i >> d >> c;
        i--;
        edges[j] = {i,d,c};
        sl.push_back({c,1,j});
    }

    ll q; cin >> q;
    vll carros(q);
    vll ans(q);
    forn(i,0,q){
        cin >> carros[i];
        sl.push_back({carros[i],0,i}); 
    }

    sort(sl.rbegin(), sl.rend());
    vll rua(n-1, INF);
    ll infcnt = n-1;
    ll tot = 0;
    
    for(auto [cc,type, idx] : sl){
        trace(cout << cc << " " << type << " " << idx << ln;)
        debug(tot);
        if(type == 1){ // edge
            auto [i, d, c] = edges[idx];
            if(rua[i] == INF){
                infcnt--;
                tot += d;
                rua[i] = d;
                continue;  
            }
            tot += min(d,rua[i]) - rua[i];
            rua[i] = min(d,rua[i]); 
            
        }else{
            if(infcnt) ans[idx] = INF;
            else ans[idx] = tot;
        }
    }

    forn(i,0,q){
        if(ans[i] == INF) cout << "impossible" << ln;
        else cout << ans[i] << ln;
    }

    return 0;
}
