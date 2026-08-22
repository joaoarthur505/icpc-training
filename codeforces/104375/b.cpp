#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int main(){
    ll n,k,l; cin >> n >> k >> l;
    ll m=n*k;
    ll resp;
    if(m%l==0) resp=m/l;
    else resp=m/l+1;
    cout << resp << endl;
}

