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
#define debugm(v) trace(cout << #v ": "; for (auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

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
        comps[sdu.find(i)].push_back(i);
    }

    vector<pll> resp;

    while (true){
        if(sz(comp) <= 1) break;
        debugm(comp);
        auto itmaior = prev(comp.end());
        auto it2maior = prev(prev(comp.end()));
        pll maior = *itmaior;
        comp.erase(itmaior); 
        pll maior2 = *it2maior;
        comp.erase(it2maior);

        resp.emplace_back(comps[maior.second].back(), comps[maior2.second].back());
        comps[maior.second].pop_back();
        comps[maior2.second].pop_back();

        if(maior.first > 1) comp.insert({maior.first-1, maior.second});
        if(maior2.first > 1) comp.insert({maior2.first-1, maior2.second});
    }

    cout << sz(resp) << ln;
    for(auto [a,b] : resp) cout << a << " " << b << ln; 
    
    return 0;
}
