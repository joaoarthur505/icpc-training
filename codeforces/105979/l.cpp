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


const ll MAX = 100'005;

vll g[MAX];

ll siz[MAX], rem[MAX], par[MAX];

void dfs_ini(map<ll,ll>& mp, ll i, ll l, ll to_open, ll acc){
    acc += par[i];
    
    if(par[i] == 1) to_open = max(to_open-1,0ll);
    else to_open++;
    
    if(to_open == 0) mp[acc]++;
    
    for(ll j : g[i]) if (j != l && !rem[j]) dfs_ini(mp, j, i, to_open, acc); 
}

void dfs_fim(map<ll,ll>& mp, ll i, ll l, ll to_close, ll acc){
    acc += par[i];
    
    if(par[i] == -1) to_close = max(to_close-1,0ll);
    else to_close++;
    
    if(to_close == 0) mp[acc]++;

    for(ll j : g[i]) if (j != l && !rem[j]) dfs_fim(mp, j, i, to_close, acc); 
}

ll dfs_sz(ll i, ll l= -1){
    siz[i] = 1;
    for(ll j : g[i]) if (j != l && !rem[j]) siz[i] += dfs_sz(j,i);
    return siz[i]; 
}

ll centroid(ll i, ll l, ll size){
    for (ll j: g[i]) if( j != l && !rem[j] && siz[j] > size / 2)
        return centroid(j,i,size);
    return i;
}

ll decomp(ll i){
    ll c = centroid(i, i, dfs_sz(i));
    debug(c);
    rem[c] = 1;
    ll ans = 0;
    map<ll,ll> gini;
    map<ll,ll> gfim;

    ll z = par[c];

    for(ll j : g[c]) if (!rem[j]) {
        map<ll,ll> lini;    
        map<ll,ll> lfim; 
        dfs_ini(lini, j, c, 0, 0);
        dfs_fim(lfim, j, c, 0, 0);

        if(z == 1){
            for(auto [k,v] : lini){
                ans += v*gfim[-(k+1)];
            }            
            for(auto [k,v] : lfim){
                ans += v*gini[-(k+1)];
            }
        }else{
            for(auto [k,v] : lini){
                ans += v*gfim[-(k-1)];
            }            

            for(auto [k,v] : lfim){
                ans += v*gini[-(k-1)];
            }
        }

        for(auto [k,v] : lini) gini[k] += v;            
        for(auto [k,v] : lfim) gfim[k] += v;            
    }

    if(z == 1) ans += gfim[-1];
    if(z == -1) ans += gini[+1];

    for(ll j: g[c]) if (!rem[j]) ans += decomp(j);
    rem[c] = 0;
    return ans;
}

int main(){
    _;
    ll n; cin >> n;

    forn(i,0,n){
        char c; cin >> c;
        if(c == '(') par[i] = +1;
        if(c == ')') par[i] = -1;
    } 

    forn(i,0,n-1){
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // map<ll,ll> lini;    
    // map<ll,ll> lfim; 

    // dfs_ini(lini, 0, -1, 0, 0);
    // dfs_fim(lfim, 0, -1, 0, 0);
    // debugm(lini);
    // debugm(lfim);
    // return 0;
    ll ans = decomp(0);
    cout << ans << ln;
}


