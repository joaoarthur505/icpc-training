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

int main() {
    ll n; cin >> n;

    vector<vll> dict(n+2, vll(n+2, 0));
    ll cnt = 0;
    forn(i, 0, n+2) forn(j, 0, i+1) dict[i][j] = ++cnt;

    function<bool (ll, ll)> ask = [&](ll i, ll j){
        // debug(i);
        // debug(j);

        cout << "? " << dict[i][j] << endl;
        bool resp;
        cin >> resp;
        return resp;
    };


    ll curri = 0, currj = 0;
    bool found = true;
    while(curri < n && found){
        ll ask_i = curri+1, ask_j = currj+1;
        found = false;

        while(ask_i<=n){
            if(ask(ask_i, ask_j)){
                curri = ask_i;
                currj = ask_j;
                found = true;
                break;
            }

            ask_i++;
        }
    }

    ll l = curri, r = n+1;
    while(l < r-1){
        ll m = (l+r)/2;
        if(ask(m, currj)){
            l = m;
        } else {
            r = m;
        }
    }

    cout << "! " << dict[l][currj] << endl;

    return 0;
}
