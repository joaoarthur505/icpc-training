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

int main(){
    _;
    
    ll n ; 
    cin >> n ; 
    ll times15 , r;
    times15 = n/15;
    r = n%15;
    if (r==0){
            
        cout << times15 << ln;
            forn(i,0,times15-1)
                {
                    cout << 1 << " " ; 
                }
                cout << 1 << ln; 
        }
        else{
            if (r == 14) {
            cout << times15+2 <<ln;
            forn(i,0,times15) {
                cout << 1 << " ";
            }
            cout << "2 11" << ln;
        }
            else if (r == 13) {
            cout << times15+2 <<ln;   
            forn(i,0,times15) {
                cout << 1 << " ";
            } 
            cout << "2 12" << ln ; 
        }
            else if (r == 12){
            cout << times15+1<<ln;
            forn(i,0,times15) {
                cout << 1 << " ";
            }
            cout << "2" << ln;
        }
        else if (r == 11) {
            cout << times15+2 <<ln;
            forn(i,0,times15) {
                cout << 1 << " ";
            }
            cout << "3 12" << ln;
        }
        else {
            cout << times15+1 <<ln;
            forn(i,0,times15) {
                cout << 1 << " ";
            }
            cout << 13-r << ln;
        }
        
        
    }
    return 0;
}