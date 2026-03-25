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

ll solve(){
    ll n, k; cin >> n >> k;
    v64 v(n);
    map<ll,ll> freq;
    forn(i, 0, n){
        cin >> v[i];
        freq[v[i]]++;
    }

    for(auto p : freq){
        if(p.second%k != 0) return 0;
        freq[p.first]/=k;
    }

    ll l = 0, r=0, counter = 0;
    map<ll,ll> curr_freq;
    while(l <= r && r < n){
        if(curr_freq[v[r]] < freq[v[r]]){
            curr_freq[v[r]]++;
            
            if(curr_freq[v[r]] <= freq[v[r]]){
                // cout << l << " " << r << ln;
                counter += r - l + 1;
            }
            r++;
        }

        else{
            curr_freq[v[l]]--;
            l++;
        }
    }

    return counter;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) cout << solve() << ln;
    return 0;
}