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

struct compare {
    bool operator () (vll& p1 , vll& p2) {
          if (p1[1]+p1[0] > p2[1]+p2[0]) {
		return false;
	  }
      if (p1[1]+p1[0] == p2[1]+p2[0] && p1[0] < p2[0])
        return false;
      return true;

    }
};
struct compare2 {
    bool operator () (vll& p1 , vll& p2) {
          if (p1[0] > p2[0]) {
		return false;
	  }
		return true;
    }
};
int main() {
     _;
    ll n ;
    cin >> n ;

    vll sidesup (n);
    vll sidesdown (n);

    set<ll> s ; 
    ll k , l ;
    forn(i,0,n)
        cin >> sidesup[i];
    forn(i,0,n)
        cin >> sidesdown[i];
    cin >> k >> l ;
    priority_queue <vll,vector<vll>,compare> pq;
    priority_queue <vll,vector<vll>,compare2> pq2;
    forn(i,0,n) {
        vll v  = {sidesup[i],sidesdown[i],i};
        pq.push(v);
    }
    ll sum = 0; 
    forn(i,0,l) {
        auto p  = pq.top();
        pq.pop();
        sum += p[0];
        sum += p[1];
    }
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        pq2.emplace(p);
    }
    forn(i,0,k-l) {
        auto p = pq2.top();
        pq2.pop();
        sum+=p[0];
    }
    cout << sum << ln;
    return 0;
}
