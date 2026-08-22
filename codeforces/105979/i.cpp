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

int main(){
    _;
    ll q; cin >> q;

    vll f(50);

    f[0]=1;f[1]=2;
    forn(i,2,50) f[i]=f[i-1]+f[i-2];

    while(q--){
        ll x,k; cin >> x >> k;
        ll resp=-1;
        forn(i,0,50){
            if(x*f[i]>=k){resp=i+1; break;}
        }

        cout << resp << ln;
    }

    return 0;
}


