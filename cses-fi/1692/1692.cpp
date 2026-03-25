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
    _; ll n; cin >> n;
    ll mod = 1<<n;
    v64 vis(mod, false);
    v64 path(n-1, 0);

    stack<ll> dfs;
    dfs.push(0);
    ll step = 0;

    while(!dfs.empty()){
        ll curr = dfs.top();

        debug(bitset<10>(curr).to_string());
        
        if(vis[curr]){
            dfs.pop();
            vis[curr] = false;
            path.pop_back();
            step--;
            continue;
        }

        vis[curr] = true;
        path.push_back(curr%2);
        step++;

        if(step == mod) break;

        ll aux_curr = curr;
        aux_curr *= 2;
        if(aux_curr >= mod) aux_curr -= mod;

        if(!vis[aux_curr]) dfs.push(aux_curr);

        aux_curr++;
        if(!vis[aux_curr]) dfs.push(aux_curr);
    }

    for(auto x : path) cout << x;
    cout << ln;

    return 0;
}
