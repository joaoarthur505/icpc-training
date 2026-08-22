#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i = (s); i<(e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

# ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u << " = " <<  u << ln)
#define debugv(v) trace(cout << #v << ": "; for(auto xx : v) cout << xx << " "; cout << ln;)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 200004;

namespace aho {
    map<char, ll> to[MAX];
    ll link[MAX], idx, term[MAX], exit[MAX], sobe[MAX];
    vll max_match(MAX, 0);

    void insert(string& s) {
        ll at = 0;
        for (char c : s) {
            auto it = to[at].find(c);
            if (it == to[at].end()) at = to[at][c] = ++idx;
            else at = it->second;
        }
        term[at]++, sobe[at]++;
        max_match[at] = sz(s);
    }

    void build() {
        queue<ll> q;
        q.push(0);
        link[0] = exit[0] = -1;
        while (sz(q)) {
            ll i = q.front(); q.pop();
            for (auto [c, j] : to[i]) {
                ll l = link[i];
                while (l != -1 && !to[l].count(c)) l = link[l];
                link[j] = l == -1 ? 0 : to[l][c];
                exit[j] = term[link[j]] ? link[j] : exit[link[j]];

                max_match[j] = max(max_match[link[j]], max_match[j]);
                if (exit[j]+1) sobe[j] += sobe[exit[j]];
                q.push(j);
            }
        }
    }
    ll query(string& s) {
        ll at = 0, ans = 0;
        for (char c : s){
            while (at != -1 && !to[at].count(c)) at = link[at];
            at = at == -1 ? 0 : to[at][c];
            ans += sobe[at];
        }
        return ans;
    }
}

int main(){
    _; ll n; cin >> n;
    forn(i,0,n) {
        string s; cin >> s;
        aho::insert(s);
    }

    aho::build;

    string r; cin >> r;
    ll m = sz(r);

    vll dp(m+1, 0);
    dp[0] = 1;

    ll at = 0;
    forn(i, 0, m){
        char c = r[i];

        while (at != -1 && !aho::to[at].count(c)) at = aho::link[at];
        at = at == -1 ? 0 : aho::to[at][c];

        ll aux = at;
        while(aux>=0){
            if(aho::term[aux]) dp[i+1] += dp[i-]
        }
    }
    return 0;
}