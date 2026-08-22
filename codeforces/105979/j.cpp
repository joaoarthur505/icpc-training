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

const ll MOD = 998244353;
const ll MAX = 1'000'005;

vll fat(MAX), inv(MAX), invfat(MAX);

void prep(){
    fat[0] = fat[1] = 1;
    inv[0]=1;
    invfat[0]=1;
    inv[1] = 1;
    invfat[1] = 1;

    forn(i,2,MAX){
        fat[i] = (fat[i-1]*i)%MOD;
        inv[i] = (MOD - (inv[MOD%i]*(MOD/i))%MOD)%MOD;
        invfat[i] = (invfat[i-1]*inv[i])%MOD;
        assert(1 == (i*inv[i])%MOD);
    }
}

int main(){
    _;
    prep();
    ll q; cin >> q;
    while(q--){
        ll n,k; cin >> n >> k;
        ll resp = (((fat[n+1]*invfat[k+1])%MOD)*invfat[n-k])%MOD;
        cout << resp << ln;
    }
}


