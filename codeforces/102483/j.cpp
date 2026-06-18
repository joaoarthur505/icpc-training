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

ll calc_t(ll n){
    ll cnt = 0;
    while(n > 0){
        n = n/2;
        cnt++;
    }
    return cnt;
}

int main() {
    _; 
    ll n; cin >> n;
    map<ll,ll> freq;

    ll especial; cin >> especial;
    forn(i, 0, n-1){
        ll a; cin >> a;
        freq[a]++;
    }
    freq[-INF] = 1;

    ll resp = 0;

    while (true){
        auto lit = prev(freq.end());
        auto llit = prev(lit);
        ll t = calc_t(lit->second);
        ll x = lit->first;
        ll y = llit->first;

        auto testa = [&](){
            // return especial - t*(x-y) >= y
            // return - t*(x-y) >= y - especial
            // return t*(x-y) <= especial - y
            return ((x-y) <= (especial-y)/t);            
        };

        if(y != -INF && testa()){
            especial -= t*(x-y);
            resp += t*(x-y);
            freq[y] += lit->second;
            freq.erase(lit);
            continue;
        }

        for(ll i = 60; i >= 0; i--){
            ll pot = 1ll<<i;
            if(pot > x-y) continue;
            // if(especial - t*pot < x-pot) continue;
            // if(- t*pot < x-pot - especial) continue;
            // if( t*pot > especial - (x-pot)) continue;
            // if(!(t*pot <= especial - (x-pot))) continue;
            if(!(pot <= (especial - (x-pot))/t)) continue;

            especial -= t*pot;
            resp += pot*t;
            x -= pot;
        }
        resp += especial - x;
        break;
    }

    cout << resp << ln;


    return 0;
}
