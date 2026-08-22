#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define _ ios::sync_with_stdio(0); cin.tie(0)

const ll MOD = 1'000'000'007;
const ll INV2 = 500'000'004;
int main(){
    _;
    assert((INV2*2)%MOD == 1);

    ll n, q; cin >> n >> q;

    vll vec(n);
    vll acc(n);
    vll acc2(n);

    for(ll i = 0; i < n; i++){
        cin >> vec[i];
        acc[i] = (vec[i] + (i == 0 ? 0 : acc[i-1]))%MOD;
        acc2[i] = (vec[i]*vec[i] + (i == 0 ? 0 : acc2[i-1]))%MOD;
    }

    while(q--){
        ll a, b; cin >> a >> b;
        a--, b--;
        if(a == b){
            cout << vec[a] << "\n";
            continue;
        }
        ll sum = (acc[b] - (a == 0 ? 0 : acc[a-1]) + MOD)%MOD;
        ll sum2 = (acc2[b] - (a == 0 ? 0 : acc2[a-1]) + MOD)%MOD;

        cout << (((sum*sum-sum2 + MOD)%MOD)*INV2)%MOD << "\n";
    }
}