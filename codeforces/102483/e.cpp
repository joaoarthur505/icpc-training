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

pll read_int(string& s, ll x){
    ll y = x;
    while(y+1 < sz(s) && s[y+1] - '0' >= 0 && s[y+1] - '0' <= 9) y++;
    ll resp = 0;
    ll pot = 1;
    for(ll i = y; i>= x; i--){
        resp += (s[i]-'0')*pot;
        pot *= 10;
    } 
    return {resp, y};
}


void parse(string& s, ll& idx, ll& idx1, vector<pair<char, vll>>& resp1){
    if(idx >= sz(s)-1) return;
    char c = s[idx];
    debug(c);
    debug(idx);
    vector<pair<char, vll>> resp;
    if(c == 'c'){
        idx += 7;
        parse(s, idx, idx1, resp1);
        idx++;                
        parse(s, idx, idx1, resp1);
        return;
    }
    if(c == 's' && s[idx+1] == 'o'){
        ll soma = 1;
        idx += 7;
        vll v;
        while(soma > 0){
            if(s[idx]-'0' <= 9 && s[idx]-'0' >= 0){
                auto p = read_int(s,idx);
                idx = p.second+1;
                v.push_back(p.first);
            }
            if(s[idx] == '(') soma++;
            if(s[idx] == ')') soma--;
            idx++;
        }
        sort(v.begin(), v.end());
        resp1[idx1++] = {'n', v};
        idx++;
        return;
    }
    
    if(c == 's' && s[idx+1] == 'h'){
        ll soma = 1;
        idx += 8;
        vll v;
        while(soma > 0){
            if(s[idx]-'0' <= 9 && s[idx]-'0' >= 0){
                auto p = read_int(s,idx);
                idx = p.second+1;
                v.push_back(p.first);
            }
            if(s[idx] == '(') soma++;
            if(s[idx] == ')') soma--;
            idx++;
        }
        sort(v.begin(), v.end());
        resp1[idx1++] = {'s', v};
        return;
    }
    if(c == '['){
        vll v;
        idx += 1;
        while(s[idx] != ']'){
            if(s[idx] == ',') idx++;
            auto p = read_int(s, idx);
            v.push_back(p.first);
            idx = p.second + 1;
        }
        resp1[idx1++] = {'n', v};
        return;
    }   


    assert(false);
}

int main() {
    _;
    string s, r; cin >> s >> r;
    ll idx = 0;
    vector<pair<char, vll>> resp1(4);
    ll idx1 = 0;
    vector<pair<char, vll>> resp2(4);
    ll idx2 = 0;

    parse(s,idx, idx1, resp1);
    
    for(auto p : resp1){
        cout << p.first << " : ";
        for(ll x : p.second) cout << x << " ";
        cout << ln;
    }
    cout << "----------------\n";
    parse(s,idx, idx2, resp2);
    for(auto p : resp2){
        cout << p.first << " : ";
        for(ll x : p.second) cout << x << " ";
        cout << ln;
    }
    return 0;
}
