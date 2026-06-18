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

bool move_t(ll i, string s){
    return (s[i] == 'L' && s[i+1] == 'I') || (s[i] == 'I' && s[i+1] == 'L');
}

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    map<char, ll> freq_old;
    forn(i, 0, n) freq_old[s[i]]++;

    vector<pair<ll, char>> aux;  
    for(auto [c, f] : freq_old){
        aux.push_back({f,c});
    }

    sort(aux.rbegin(), aux.rend());

    vector<char> order = {'I', 'L', 'T'};

    ll i = 0;
    vll freq(3);
    for(auto [f, c] : aux){
        freq[i] = f;
        forn(j, 0, n) if(s[j] == c) s[j] = order[i];
        i++;
    }

    cout << s << ln;
    cout << freq[0] << " " << freq[1] << " " << freq[2] << ln;

    vll move;
    for(ll j = n-2; j >= 0; j--){
        ll shift = 0;
        debug(j);
        if((freq[2] < freq[1]) && move_t(j, s)){
            move.push_back(j);
            freq[2]++;

            shift++;
        }
        
        if(s[j] != 'I' && s[j+1] == 'I'){
            while(freq[0] > freq[1]){
                move.push_back(j+shift);
                move.push_back(j+shift+1);
                shift +=2;

                freq[1]++;
                freq[2]++;
            }
        }

        if( (s[j] == 'I') && (s[j+1] != 'I')){
            debug(j);
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
