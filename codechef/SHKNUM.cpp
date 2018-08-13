#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef unsigned long long int ul;
 
#define MOD 1000000007
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vsort(v) sort(v.begin(), v.end())
#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout << (#x) << " is " << (x) << endl
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
 
int main(void){
	fast();
	vl v;
	ll i,j;
	rep(i,0,31){
		rep(j,i+1,32){
			ll x = ((ll)1<<i) + ((ll)1<<j);
			v.pb(x);
		}
	}
	vsort(v);
	// for(auto it = v.begin();it<v.end();it++){
	// 	cout<<*it<<"\n";
	// }
	int t;
	get(t);
	while(t--){
		ll n;
		get(n);
		ll r=0;
		auto it = lower_bound(all(v), n);
		if(n<3){
			r=3-n;
		}
		else if(*it != n){
			r = *it - n;
			// pln("in");
			// pln(r);
			it--;
			ll tm = n - *it;
			if(tm<r) r= tm;
		}
		// pln(*it);
		// it--;
		pln(r);
	}
}
 
// 4294967296 
 
