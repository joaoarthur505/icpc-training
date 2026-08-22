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

bool testa(vll vec, ll d){
    if(sz(vec) == 0) return true;
    ll n = sz(vec);
    ll anc = vec[0];
    ll parede = 0;
    ll st = max(vec[0]-d + 1, parede);

    forn(i,1,n){
        if(vec[i] - anc < d){
            st = max(vec[i]-d + 1, parede);
            continue;
        }
        if(vec[i] < st + 2*d) return false;
        anc = vec[i];
        parede = st + 2*d;
        st = max(vec[i]-d + 1, parede);
    }
    return true;
};

int main(){
    _;  
    ll t = 1;
    // cin >> t;

    while(t--){
        ll n, d; cin >> n >> d;
        bool printo = false;
        vector<vll> inv(n);
        vll vec(n);
        ll big = 0;
        
        forn(i,0,n){
            cin >> vec[i];
            big = max(big, vec[i]);
            inv[vec[i]].push_back(i); 
        }
        
        debugv(vec); 
        forn(idx,0,big+1){
            auto& v = inv[idx];
            if(testa(v, d)){
                cout << idx << ln; 
                printo = true;
                break;
            }
        }
        if(!printo) cout << big+1 << ln;
    }
    return 0;
}