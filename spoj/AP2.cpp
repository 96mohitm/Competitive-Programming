#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
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
		ll c1,c2,c3;
		get(c1);get(c2);get(c3);
		ll n = (2l*c3)/(c1+c2);
		ll d = (c2-c1);
		d=  d/(n-5l);
		ll a = (c1+c2 - n*d + d)/2l;
		// watch(d);
		// watch(a);
		pln(n);
		ll j = a;
		rep(i,0,n){
			pls(j);
			j+=d;
		}
		pln("");
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
