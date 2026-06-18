#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    bool leu=true;
    vll v(8);
    for(ll i=0;i<8;i++){
        cin >> v[i];
        if(v[i]==9) leu=false;
    }

    if(leu) cout << "S" << endl;
    else cout << "F" << endl;

    return 0;
}
