#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
typedef long double 	ld;

typedef pair<int, int> 	pii;
typedef vector<int> 	vi;
typedef vector<pii>		vpi;
typedef vector<ll> 		vl;
typedef vector<vi> 		vvi;
typedef vector<ll> 		vl;
typedef vector<vl> 		vvl;

typedef unsigned long long int 	ul;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
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

void solve(){
	int t;
	get(t);
	while(t--){
		int n,m,q;
		get(n);get(m);get(q);
		vi r,c;
		if(q==0){
			int result=n*m;
			pln(result);
			continue;
		}
		while(q--){
			int x;
			get(x);
			r.pb(x);
			get(x);
			c.pb(x);
		}
		vsort(r);
		vsort(c);
		int rm,cm;
		//row.
		if(r[0]==1)
			rm = 0;
		else
			rm = r[0]-1;
		rep(i,1,sz(r)){
			int x = r[i]-r[i-1]-1;
			rm = max(x,rm);
		}
		if(r[sz(r)-1]!=n){
			int x = n-r[sz(r)-1];
			rm=max(rm,x);
		}
		//column
		if(c[0]==1)
			cm= 0;
		else
			cm = c[0]-1;
		rep(i,1,sz(c)){
			int x = c[i]-c[i-1]-1;
			cm = max(x,cm);
		}
		if(c[sz(c)-1]!=m){
			int x = m-c[sz(c)-1];
			cm=max(cm,x);
		}
		int result=cm*rm;
		pln(result);
	}
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
