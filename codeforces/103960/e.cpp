#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll range = 1e6+1;

int main() {
    ll n,resp=0; cin >> n;
    vll h(n),freq(range);
    for(ll i=0;i<n;i++) cin >> h[i];
    for(ll i=0;i<n;i++){
        if(freq[h[i]]==0){resp ++; freq[h[i]]++;}
        freq[h[i]]--; freq[h[i]-1]++;
    }
    cout << resp << endl;

    return 0;
}
