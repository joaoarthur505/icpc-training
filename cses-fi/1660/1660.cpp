#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

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

int main() {
    _; ll n, target; cin >> n >> target;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    ll counter = 0;
    
    ll l = 0;
    ll sum = v[0];
    forn(r, 1, n){
        if(sum == target) counter++;

        while(sum + v[r] > target){
            sum -= v[l];
            l++;
        }

        sum += v[r];
    }
    if(sum == target) counter++;
    
    cout << counter << ln;
    return 0;
}
