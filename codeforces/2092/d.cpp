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

bool cmp(pll p1, pll p2){
    if(p2.second == p1.second) return p2.first < p1.first;
    return p2.second < p1.second;
}

vll translate(string s){
    ll n = sz(s);
    vector<pll> freq(26);
    forn(i, 0, 26) freq[i] = {i, 0};

    forn(i, 0, n) freq[s[i] - 'A'].second++;
    sort(freq.begin(), freq.end(), cmp);

    trace(
        forn(i, 0, 26) cout << freq[i].second << " ";
        cout << ln;
    )

    vll v(n);
    forn(i, 0, n){
        forn(j, 0, 26){
            if(s[i] - 'A' == freq[j].first) v[i] = j;
        }
    }

    debugv(v);

    return v;
}

bool move_t(ll i, vll s){
    return (s[i] == 1 && s[i+1] == 0) || (s[i] == 0 && s[i+1] == 1);
}

void solve(){
    ll n; cin >> n;
    string s_old; cin >> s_old;

    vll s = translate(s_old);
    vll freq(3);
    forn(i, 0, n) freq[s[i]]++;

    vll move;
    for(ll j = n-2; j >= 0; j--){
        ll shift = 0;
        if((freq[2] < freq[1]) && move_t(j, s)){
            move.push_back(j);
            freq[2]++;

            shift++;
        }
        
        if(s[j] != 0 && s[j+1] == 0){
            while(freq[0] > freq[1]){
                move.push_back(j+shift);
                move.push_back(j+shift+1);
                shift +=2;

                freq[1]++;
                freq[2]++;
            }
        }

        if( (s[j] == 0) && (s[j+1] != 0)){
            while(freq[0] > freq[1]){
                move.push_back(j);
                move.push_back(j);

                freq[1]++;
                freq[2]++;
            }
        }
    }

    if(freq[0] != freq[2]) cout << -1 << ln;
    else{
        cout << sz(move) << ln;
        for(auto x : move) cout << x+1 << ln;
    }
}

int main() {
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
