#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ll n,s1=0,s2=0; cin >> n;
    vll joao(2), maria(2), mesa(n), cartas(14,4);
    for(ll i=0;i<2;i++){
        cin >> joao[i]; cartas[joao[i]]--;
        if(joao[i]>10) joao[i]=10;
        s1+=joao[i];
    }
    for(ll i=0;i<2;i++){
        cin >> maria[i]; cartas[maria[i]]--;
        if(maria[i]>10) maria[i]=10;
        s2+=maria[i];
    }
    for(ll i=0;i<n;i++){
        cin >> mesa[i]; cartas[mesa[i]]--;
        if(mesa[i]>10) mesa[i]=10;
        s1+=mesa[i]; s2+=mesa[i];
    }

    if(s2>=s1 && s2>13){
        if(cartas[23-s2]>0) cout << 23-s2 << endl;
        else cout << -1 << endl;
    }

    else if(s2>=s1 && s2==13) cout << 10 << endl;

    else if(s1>s2 && s1==13) cout << -1 << endl;

    else if(s1>s2 && s1>13){
        ll j=23-s1+1;
        while(cartas[j]==0)j++;
        if(j>23-s2) cout << -1 << endl;
        else if(j>10) cout << 10 << endl;
        else cout << j << endl;
    }

    return 0;
}

