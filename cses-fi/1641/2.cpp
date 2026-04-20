// https://vjudge.net/contest/796563#problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main() {
    ll n; cin >> n;
    vector<ll> v(n-1);
    forn(i,0,n-1){
        cin >> v[i];
    } 
    sort(v.begin(),v.end());
    forn(i,0,n-1){
        
        if (v[i] - v[i+1] != -1){
            cout << v[i] + 1;
            return -1;
        }
    }
    cout << n;
}