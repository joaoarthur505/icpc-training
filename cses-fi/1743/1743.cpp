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
    _; string s; cin >> s;
    map<char,ll> freq;
    ll n = sz(s);
    forn(i, 0, n) freq[s[i]]++;

    string snew;
    char especial;
    forn(i, 0, n){
        debug(snew);
        ll maximo = 0;
        for(auto [c, v] : freq){
            if(maximo < v){
                maximo = v;
                especial = c;
            }
        }

        if((n-sz(snew))%2 == 1 && maximo >= ((n-sz(snew))+1)/2){
            break;
        }

        char add = freq.begin()->first;
        if(sz(snew) != 0 && snew.back() == add){
            auto it = next(freq.begin());
            assert(it != freq.end());
            add = it->first;
        }
 
        snew.push_back(add);
        freq[add]--;
        if(freq[add] == 0) freq.erase(add);
    }

    if(sz(snew) < n){
        freq.erase(especial);
        while(!freq.empty()){
            snew.push_back(especial);
            char add = freq.begin()->first;
            snew.push_back(add);
            debug(snew);
            freq[add]--;
            if(freq[add] == 0) freq.erase(add);

            trace(
                for(auto [c,v] : freq) cout << c << " " << v << ln;
            );
        }

        snew.push_back(especial);
    }

    bool check = true;
    if(sz(snew) != n) check = false;
    else forn(i, 0, n-1) if(snew[i] == snew[i+1]) check = false;

    if(check) cout << snew << ln;
    else cout << -1 << ln;

    return 0;
}
