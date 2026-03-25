#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;
    if(k%2 == 1){
        forn(i, 0, k) cout << n << " \n"[i == k-1];
        return;
    }

    ll pot = 1, a = 1;
    while(pot*2 <= n){
        pot = pot*2;
        a++;
    }

    vector<vector<bool>> bin(a, vector<bool>(k, false));

    ll ind = -1;
    forn(i, 0, a){
        if(n >= pot){
            if(ind < k-1)ind++;
            forn(j, 0, k){
                bin[i][j] = (j != ind);
            }

            n -= pot;
        }
        else{
            for(ll j = 1; j<= ind;j+=2){
                bin[i][j] = true;
                bin[i][j-1] = true;
            }
        }
        pot = pot/2;
    }

    forn(j, 0, k){
        ll pow = 1;
        ll num = 0;
        for(ll i = a-1; i >= 0; i--){
            if(bin[i][j]) num += pow;
            pow = pow*2;
        }

        cout << num << " ";
    }
    cout << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}