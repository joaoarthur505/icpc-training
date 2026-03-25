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
const ll MAX = 1000004;
const ll MAXN = 5000;
const ll MOD = 1000000007;

namespace aho {
    // vector<v64> to(MAX, v64(26, -1));
    // // vector<map<char, ll>> to(MAX);
    // vector<ll> link(MAX), term(MAX), exit(MAX), size_term(MAX), dp(MAXN);

    vector<v64> to(1, v64(26, -1));
    vector<ll> link(1), term(1), exit(1), size_term(1),  dp(MAXN);
    ll idx = 0;

    ll conv(char c){
        return c - 'a';
    }

    void insert(string& s) {
        // debug(s);
        ll at = 0;
        for (char c : s) {
            // auto it = to[at].find(c);
            // if (it == to[at].end()) at = to[at][c] = ++idx;
            // else at = it->second;

            // if(to[at][conv(c)] == -1) at = to[at][conv(c)] = ++idx; 
            // else at = to[at][conv(c)];
            // debug(at);
            // trace(
            //     forn(i, 0, 26) cout << to[at][i] << " ";
            //     cout << ln;
            // );

            if (to[at][conv(c)] == -1) {
                to[at][conv(c)] = to.size();
                to.emplace_back(26, -1);
                link.push_back(0);
                term.push_back(0);
                exit.push_back(0);
                size_term.push_back(0);
            }
            at = to[at][conv(c)];
            idx = sz(to);
        }
        term[at]++, size_term[at] = sz(s);
    }

    void build() {
        queue<ll> q;
        q.push(0);
        link[0] = exit[0] = -1;
        while (sz(q)) {
            ll i = q.front(); q.pop();
            forn(c, 0, 26) {
                if(to[i][c] == -1) continue;
                ll j = to[i][c];
                ll l = link[i];
                while(l != -1 && to[l][c] == -1) l = link[l];
                link[j] = l == -1 ? 0 : to[l][c];
                exit[j] = term[link[j]] ? link[j] : exit[link[j]];

                q.push(j);
            }
            // for (auto [c, j] : to[i]) {
            //     ll l = link[i];
            //     while (l != -1 && !to[l].count(c)) l = link[l];
            //     link[j] = l == -1 ? 0 : to[l][c];
            //     exit[j] = term[link[j]] ? link[j] : exit[link[j]];

            //     q.push(j);
            // }
        }
    }

    void solve(string s){
        ll n = sz(s);
        dp[0] = 1;

        ll at = 0;
        forn(i, 1, n+1){
            ll c = conv(s[i-1]);
            while (at != -1 && to[at][c] == -1) at = link[at];
            at = at == -1 ? 0 : to[at][c];

            ll aux = at;
            while(aux != -1){
                if(term[aux]){
                    dp[i] = (dp[i] + dp[i-size_term[aux]])%MOD;
                }

                aux = exit[aux];
            }
        }
    }
}


int main() {
    _; string s; cin >> s;
    ll n = sz(s);
    ll k; cin >> k;
    forn(i, 0, k){
        string a; cin >> a;
        aho::insert(a);
    }

    aho::build();
    aho::solve(s);

    trace(
        // forn(i, 0, aho::idx){
        //     cout << i << ": ";
        //     forn(j, 0, 3) cout << aho::to[i][j] << " \n"[j==3];
        // }

        // cout << ln;

        forn(i, 0, n+1) cout << aho::dp[i] << " \n"[i == n];
    );

    cout << aho::dp[n] << ln;
    return 0;
}
 