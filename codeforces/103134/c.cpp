#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;


bool f (multiset<ll>& novoN, multiset<ll> N, ll q) {
    novoN = N;
    if (q == 0) {
        if (novoN.find(0) == novoN.end()) {
            //cout << qOrg << ' ' << a << ln;
            return false;
        }
        novoN.erase(novoN.find(0));
        return true;
    }
    while (q > 0) {
        ll a = q%10;
        if (novoN.find(a) == novoN.end()) {
            //cout << qOrg << ' ' << a << ln;
            return false;
        }
        novoN.erase(novoN.find(a));
        q = q / 10;
    }
    return true;
}


void func (vector<ll>& v, vector<ll> Q0, vector<ll> Q, multiset<ll> N, ll i, ll lenQ)  {
    if (i == lenQ) {
        v = Q0;
        return;
    }
    vector<ll> Q1 = Q0;
    func(Q1, Q1, Q, N, i+1, lenQ);

    ll l1 = Q1.size();
    //cout << "l1 " << l1 << ln;

    multiset<ll> novoN;
    bool banana = f(novoN, N, Q[i]);
    //cout << banana << ln;
    if (banana) {
        vector<ll> Q2 = Q0;
        Q2.push_back(Q[i]);

        func(Q2, Q2, Q, novoN, i+1, lenQ);

        ll l2 = Q2.size();
        //cout << "l2 " << l2 << ln;

        if (l1 > l2) {
            v = Q1;
        } else {
            v = Q2;
        }
    } else {
        v = Q1;
    }
}

int main(){
    ll nN, nQ;
    cin >> nQ >> nN;

    vector<ll> Q(nQ);
    forn(i, 0, nQ) {
        cin >> Q[i];
    }

    multiset<ll> N;
    forn(i, 0, nN) {
        ll x;
        cin >> x;
        N.insert(x);
    }

    vector<ll> maxQ;
    func(maxQ, maxQ, Q, N, 0, nQ);

    ll n = maxQ.size();
    cout << n << ln;
    forn(i, 0, n) {
        cout << maxQ[i] << " \n"[i==n-1];
    }

    return 0;
}