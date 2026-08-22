#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int main() {
    ll n; cin >> n;
    set<string> uni, used;

    for(ll j = 0; j < n; j++) {
        ll t; cin >> t;
        string name;
        for(ll i = 0; i < t; i++) {
            string a; cin >> a;
            name.push_back(a[0]);
        }

        if(used.count(name)) continue;
        if(uni.count(name)){
            uni.erase(name);
            used.insert(name);
            continue;
        }
        uni.insert(name);
    }

    cout << uni.size() << endl;
}