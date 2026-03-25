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
    v64 path(n, 0);

    // function<void (ll, ll, bool& )> dfs = [&](ll curr, ll step, bool &found){
    //     if(step == mod-1) {
    //         found = true;
    //         return;
    //     }
 
    //     debug(bitset<20>(curr).to_string());
    //     debug(step);

    //     vis[curr] = true;
    //     ll aux_curr = curr;
    //     aux_curr *= 2;
    //     if(aux_curr >= mod) aux_curr -= mod;

    //     path.push_back(0);
    //     if(!vis[aux_curr])dfs(aux_curr, step+1, found);
    //     if(found) return;

    //     path.pop_back();
        
    //     aux_curr++;
    //     path.push_back(1);
    //     if(!vis[aux_curr])dfs(aux_curr, step+1, found);
    //     if(found) return;

    //     path.pop_back();
    //     vis[curr] = false;
    // };

    // bool found = false;
    // dfs(0, 0, found);

    stack<ll> dfs;
    dfs.push(0);
    ll step = 0;

    while(!dfs.empty()){
        ll curr = dfs.top();
        
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

        if(step == mod-1) break;

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
