#include <bits/stdc++.h>
using namespace std;
typedef long long 	ll;
#define get(x) cin >> x
#define pln(x) cout << x << "\n"
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
ll fastexpo(ll n, ll m){
	if(m<=1)
		return n;
	if(m&1){
		return (n*(fastexpo(n,m-1)%10))%10;
	}
	ll r = fastexpo(n,m/2)%10;
	return (r*r)%10;
}
void solve(){
	int t;
	get(t);
	while(t--){
		ll n,m,r;
		get(n);get(m);
		n=n%10;
		if(n==0)
			pln("0");
		else if(m==0)
			pln("1");
		else
			pln(fastexpo(n,m));
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
