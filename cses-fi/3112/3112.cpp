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

ll counter = 0;

bool ask(ll x){
    counter++;
    cout << "? " << x << endl;
    string s;
    cin >> s;

    return s[0] == 'Y';
}

int main() {
    ll l = 1, r = 1e9, ans;
    while(l <= r){
        ll mid = (l+r)/2;
        if(ask(mid)){
            l = mid+1;
        } else {
            ans = mid;
            r = mid-1;
        }
    }

    debug(counter);

    cout << "! " << ans << ln;
    return 0;
}
