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

struct dsu {
    vll id, len;

    dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    bool uni(ll a, ll b){   
        a = find(a), b = find(b);
        if(a == b) return false;
        if(len[a] < len[b]) swap(a, b);
        len[a] += len[b], id[b] = a;
        return true;
    }
};

int main() {
    _; ll n, m; cin >> n >> m;
    dsu sdu(n);
    vector<vll> comps(n);
    set<pll> comp;

    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        sdu.uni(a, b);
    }
    forn(i, 0, n){
        comp.insert({sdu.len[sdu.find(i)], sdu.find(i)});
    
    }
    map<ll,ll> freq;
    for(auto [a,b] : comp) freq[a]++;

    vll dp(n+1);
    vll tb(n+1);
    dp[0] = 1;
    ll tar = n/2;

    for(auto [k,v] : freq){
        debug(k);
        debug(v);
        vll aux(n+1);
        forn(i,0,tar+1){
            if(i+k > n) break;
            if(dp[i] == 1 && aux[i] < v){
                if(dp[i+k] == 0){
                    dp[i+k] = 1;
                    aux[i+k] = aux[i]+1;
                    tb[i+k] = k;
                }
            }
        }
    }

    ll best = 0;
    for(ll i = n/2; i >= 0; i--) if(dp[i]){
        best = i;
        break;
    }

    vll used;
    ll x = best;
    while(x > 0){
        used.push_back(tb[x]);
        x -= tb[x];
    }

    set<ll> pais;
    while(sz(used)){
        ll t= used.back();
        used.pop_back();
        auto it = comp.lower_bound({t,-1});
        pais.insert(it->second);
        comp.erase(it);
    }
    debugv(pais);
    debugv(dp);
    cout << best << ln;

    vll ladoa;
    vll ladob;

    forn(i,0,n){
        if(pais.count(sdu.find(i))) ladoa.push_back(i);
        else ladob.push_back(i);
    }

    forn(i,0,best){
        cout << ladoa[i] << " " << ladob[i] << ln;
    } 
    return 0;
}
