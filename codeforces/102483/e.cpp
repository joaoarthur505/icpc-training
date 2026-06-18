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

bool is_digit(char c){
    return ((ll)c >= 48) && ((ll)c <= 57);
}

ll read_num(string s, ll &ind){
    vll v;
    while(is_digit(s[ind])){
        v.push_back(s[ind] - '0');
        ind++;
    }

    ll pot = 1;
    ll num = 0;

    for(ll i = sz(v)-1; i >=0; i--){
        num += v[i]*pot;
        pot *= 10;
    }

    return num;
}

pair<ll,vector<ll>> read_vec(string s, ll &ind, char ini, char fim, ll type){
    assert(s[ind] == ini);
    ind++;
    ll depth = 1;

    vll v;
    while(depth > 0){
        if(s[ind] == ini) depth++;
        if(s[ind] == fim) depth--;
        if(is_digit(s[ind])){
            v.push_back(read_num(s, ind));
            continue;
        }
        ind++;
    }
    
    sort(v.begin(), v.end());
    assert(sz(v) > 0);
    if(v[0] == v.back()) type = 0;

    return {type, v};
}

vector<pair<ll, vll>> read(){ // 0 -> ordenado, 1-> shuffle
    vector<pair<ll,vll>> v;
    v.push_back({0, {}}); 
    string s; cin >> s;

    debug(s);

    ll ind = 0;
    while(ind < sz(s)){
        debug(ind);
        if(s[ind] == '['){
            auto nv = read_vec(s, ind, '[', ']', 0);

            if(nv.first == 0 && !empty(v) && (v.back()).first == 0) for(auto x : nv.second) (v.back()).second.push_back(x);
            else v.push_back(nv);

            continue;
        }
        if(s[ind] == 's'){
            ind++;
            ll type;
            if(s[ind] == 'o'){
                ind+=5;
                type = 0;
            }
            if(s[ind] == 'h'){
                ind += 6;
                type = 1;
            }

            auto nv = read_vec(s, ind, '(', ')', type);

            if(nv.first == 0 && !empty(v) && (v.back()).first == 0) for(auto x : nv.second) (v.back()).second.push_back(x);
            else v.push_back(nv);

            continue;
        }

        ind++;
    }

    return v;
}

int main() {
    _;
    auto v1 = read();
    trace(
        for(auto [t, vec] : v1){
            debug(t);
            debugv(vec);
        }
    );

    auto v2 = read();

    bool eq = true;

    if(sz(v1) != sz(v2)) eq = false;

    if(eq){
        ll n = sz(v1);
        forn(i, 0, n){
            ll t1 = v1[i].first;
            ll t2 = v2[i].first;
            vll vec1 = v1[i].second;
            vll vec2 = v2[i].second;
            
            if(t1 != t2) eq = false;
            if(sz(vec1) != sz(vec2)) eq = false;
            if(!eq) break;

            ll m = sz(vec1);
            forn(j, 0, m) if(vec1[j] != vec2[j]){
                eq = false;
                break;
            } 
        }
    }

    if(!eq) cout << "not ";
    cout << "equal" << ln; 

    return 0;
}
