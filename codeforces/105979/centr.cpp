#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u)
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

const ll MAX = 100'005;

vll g[MAX];

ll siz[MAX], rem[MAX];

void dfs(vll& path, ll i, ll l = -1, ll d = 0){

    for(ll j : g[i]) if (j != l && !rem[j]) dfs(path, j, i, d+1); 
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

ll decomp(ll i, ll k){
    ll c = centroid(i, i, dfs_sz(i));
    rem[c] = 1;

    ll ans = 0;
    vll cnt(siz[i]);
    cnt[0] = 1;

    for(ll j : g[c]) if (!rem[j]) {
        vll path;
        dfs(path, j);
    }

    for(ll j: g[c]) if (!rem[j]) ans += decomp(j,k);
    rem[c] = 0;
    return ans;
}

int main(){
    _;
}


