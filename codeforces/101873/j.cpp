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

vector<string> nvs;
vector<v64> g;
vector<vector<p64>> dp1;
vector<p64> dp2;

pair<bool, ll> match(string s1, string s2){
    ll n = sz(s1);
    ll m = sz(s2);

    ll best = 0;
    forn(i, 0, m){
        forn(j, 0, n+1){
            if(s2[i+j] != s1[j])break;
            if(j == n-1){
                return {true, -1};
            }
            if(i+j == m-1){
                best = max(best, j+1);
                break;
            }
        }
    }
    return {false, n - best};
}

string decoder(ll mask, ll linguica){
    v64 ind;
    ll last = dp2[mask].second;
    ind.push_back(last);

    // debug(mask);

    while(last!=-1){
        // debug(last);
        // ll x; cin >> x;
        ll aux = last;
        last = dp1[mask][aux].second;
        mask = mask^(1<<aux);
        ind.push_back(last);
    }

    ind.pop_back();
    reverse(ind.begin(), ind.end());

    if(ind.empty()){
        return "";
    }

    string s = nvs[ind[0]];
    forn(i, 1, sz(ind)){
        string s_new = nvs[ind[i]];
        forn(j, sz(s_new)-g[ind[i-1]][ind[i]],sz(s_new)){
            s.push_back(s_new[j]);
        }
    }

    while(sz(s) < linguica){
        s.push_back('X');
    }

    return s;
}

struct state{
    ll num_lines;
    ll open_mask;

    state(ll n, ll o){
        num_lines = n;
        open_mask = o;
    }
};

int main(){
    _; ll L, C, n; cin >> L >> C >> n; 
    vector<string> vs(n);

    forn(i, 0, n) cin >> vs[i];

    forn(i, 0, n){
        bool deu_ruim = false;
        forn(j, 0, n){
            if(i == j) continue;
            auto p = match(vs[i], vs[j]);
            if(p.first) deu_ruim = true; 
        }
        if(!deu_ruim) nvs.push_back(vs[i]);
    }

    debugv(nvs);
    n = sz(nvs);
    g.resize(n, v64(n, 0));

    forn(i, 0, n){
        forn(j, 0, n){
            if(i == j) continue;
            g[i][j] = match(nvs[j], nvs[i]).second;
        }
    }

    forn(i, 0, n) debugv(g[i]);

    dp1.resize(1<<n, vector<p64>(n, {INF, -1})); 
    forn(mask, 0, 1<<n){
        forn(j, 0, n){
            if(mask == 0) dp1[mask][j] = {0,-1};

            if(!(mask&(1<<j)))continue;

            ll new_mask = mask^(1<<j);
            if(new_mask == 0) dp1[mask][j] = {sz(nvs[j]), -1};
            
            forn(k, 0, n){
                if(!(new_mask&(1<<k)))continue;
                if(dp1[mask][j].first > dp1[new_mask][k].first + g[k][j]){
                    dp1[mask][j] = {dp1[new_mask][k].first + g[k][j], k};
                }
            }
        }
    }

    dp2.resize(1<<n,{INF, -1});

    forn(mask, 0, 1<<n){
        if(mask == 0){
            dp2[mask] = {0, -1};
        }
        forn(i, 0, n){
            if(dp2[mask].first > dp1[mask][i].first){
                dp2[mask] = {dp1[mask][i].first, i};
            }
        }
    }

    vector<state> dp3((1<< n), state(L+1, n));
    dp3[0].num_lines = 1;
    dp3[0].open_mask = 0;

    forn(mask, 0, 1<<n){
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i))) continue;
            ll next_mask = mask ^ (1<<i);
            ll next_line = dp3[mask].open_mask ^ (1<<i);
            if(dp2[next_line].first <= C){
                state aux(dp3[mask].num_lines, next_line);
                if(aux.num_lines < dp3[next_mask].num_lines){
                    dp3[next_mask] = aux;
                }
                else if(aux.num_lines == dp3[next_mask].num_lines){
                    if(dp2[aux.open_mask] < dp2[dp3[next_mask].open_mask]){
                        dp3[next_mask] = aux;
                    }
                }
            }
            if(dp2[(1<<i)].first > C){
                cout << "impossible" << ln;
                return 0;
            }
            else{
                if(dp3[mask].num_lines == L) continue;
                state aux(dp3[mask].num_lines + 1, 1<<i);
                if(aux.num_lines < dp3[next_mask].num_lines){
                    dp3[next_mask] = aux;
                }
                else if(aux.num_lines == dp3[next_mask].num_lines){
                    if(dp2[aux.open_mask] < dp2[dp3[next_mask].open_mask]){
                        dp3[next_mask] = aux;
                    }
                }
            }
        }
    }

    ll mask_all = (1<<n)-1;

    if(dp3[mask_all].num_lines > L){
        cout << "impossible" << ln;
        return 0;
    }

    ll lines = 0;
    while(mask_all!=0){
        lines++;
        cout << decoder(dp3[mask_all].open_mask, C) << ln;
        mask_all ^= dp3[mask_all].open_mask;
    }

    string linguica;
    forn(i, 0, C) linguica.push_back('X');
    while(lines < L){
        lines++;
        cout << linguica << ln;
    }

    // trace(
    //     forn(i, 0, 1<<n){
    //         cout << dp2[i].first << " ";
    //     }
    //     cout << ln;
 
    //     forn(i, 0, 1<<n){
    //         cout << dp2[i].second << " ";
    //     }
    //     cout << ln;

    //     forn(i, 0, 1<<n){
    //         cout << decoder(i) << " ";
    //     }
    //     cout << ln;
    // );

    return 0;
}