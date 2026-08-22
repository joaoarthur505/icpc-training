#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i = (s); i<(e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

# ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln;)
#define debugm(v) trace(cout << #v ": "; for (auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln;)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
    _;
    ll n, q; cin >> n >> q;

    multiset<pll> ms;
    ordered_set os;
    
    forn(i,0,n){
        ll x; cin >> x;
        ms.insert({x,i});
        os.insert({x,i});
    }
    ll idx = n;

    while (q--){
        ll t; cin >> t;
        debug(q);
        debugm(ms);
        debugm(os);
        if(t == 1){
            ll k; cin >> k;
            auto it = ms.lower_bound({k,0});
            if(it == ms.end()){
                ms.insert({k,idx});
                os.insert({k, idx});
                idx++;
            }   
            else if(k != it->first){
                os.erase(*it);
                os.insert({k,idx});
                ms.erase(it);
                ms.insert({k,idx});
                idx++;
            }
        }else{
            ll a, b; cin >> a >> b;
            auto ait = ms.lower_bound({a,0});
            auto bit = ms.upper_bound({b,INF});
            pll aa = (ait == ms.end() ? (pll){INF,INF} : *ait);
            pll bb = (bit == ms.end() ? (pll){INF,INF} : *bit);
            trace(
                cout << aa.first << " " << aa.second << ln;
                cout << bb.first << " " << bb.second << ln;
            )
            if(aa == (pll){INF,INF}){
                cout << 0 << ln; 
                trace(cout << "-----------------\n\n");
                continue;
            }

            if(bb == (pll){INF,INF}){
                ll posa = os.order_of_key(aa);
                cout << sz(ms) - posa << ln;
                trace(cout << "-----------------\n\n");
                continue;
            }
            ll posa = os.order_of_key(aa);
            ll posb = os.order_of_key(bb); 
            debug(posa);
            debug(posb);
            cout << posb - posa << ln;
        }
        trace(cout << "-----------------\n\n");
    }
    
    return 0;
}   